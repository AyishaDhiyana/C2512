#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <numeric>
#include <thread>

using namespace std;

class Vaccination {
private:
    std::string VaccinationId;
    long long DosesAdministered;

public:
    Vaccination(std::string p_VaccinationId, long long p_DosesAdministered)
        : VaccinationId(p_VaccinationId), DosesAdministered(p_DosesAdministered) {}

    string getVaccinationId() const { return VaccinationId; }
    long long getDosesAdministered() const { return DosesAdministered; }  
};

void sliceSum(int* doses,int startIndex, int endIndex, int& sum)
{
    sum = std::accumulate(doses + startIndex , doses + endIndex, 0);
}
void server(int read_from_pipe, int write_to_pipe) {
    int doses[100];
    int num_vaccines;

    read(read_from_pipe, &num_vaccines, sizeof(num_vaccines));

    read(read_from_pipe, doses, sizeof(int) * num_vaccines);

    int sum1 = 0, sum2 = 0, sum3 = 0;
    int sliceSize = (num_vaccines / 3);

    std::thread thrSum1(sliceSum, doses, 0, sliceSize, std::ref(sum1));
    std::thread thrSum2(sliceSum, doses, sliceSize, 2 * sliceSize, std::ref(sum2));
    std::thread thrSum3(sliceSum, doses, 2 * sliceSize, num_vaccines,  std::ref(sum3));

    thrSum1.join();
    thrSum2.join();
    thrSum3.join();

    int totalSum = sum1 + sum2 + sum3;
    write(write_to_pipe, &totalSum, sizeof(totalSum));

}

void client(vector<Vaccination>& vaccinations, int write_to_pipe, int read_from_pipe) {
  
    vaccinations.emplace_back("V001", 3);
    vaccinations.emplace_back("V002", 4);
    vaccinations.emplace_back("V003", 5);
    vaccinations.emplace_back("V004", 6);
    vaccinations.emplace_back("V005", 10);

    int num_vaccines = vaccinations.size();
    int doses[100];

    for (int i = 0; i < num_vaccines; i++) {
        doses[i] = vaccinations[i].getDosesAdministered();
    }
    write(write_to_pipe, &num_vaccines, sizeof(num_vaccines));
    write(write_to_pipe, doses, sizeof(int) * num_vaccines);
    int sum;
    read(read_from_pipe, &sum, sizeof(sum));

    cout << "Sum of doses: " << sum << endl;
}

int main() {
    vector<Vaccination> vaccinations;
    int pipe1[2]; //client - server
    int pipe2[2]; //server - client

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe not created");
        return 1; 
    }

    pid_t pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
       
        close(pipe1[1]); 
        close(pipe2[0]); 
        server(pipe1[0], pipe2[1]);
        close(pipe1[0]); 
        close(pipe2[1]);
        
    } else {
       
        close(pipe1[0]); 
        close(pipe2[1]);
        client(vaccinations, pipe1[1], pipe2[0]);
        close(pipe1[1]); 
        close(pipe2[0]); 

        wait(nullptr);  //wait for child to complete
    }

    return 0;
}
