#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

class Vaccination {
private:
    std::string VaccinationId;
    int DosesAdministered;

public:
    Vaccination(std::string p_VaccinationId, int p_DosesAdministered)
        : VaccinationId(p_VaccinationId), DosesAdministered(p_DosesAdministered) {}

    string getVaccinationId() const { return VaccinationId; }
    int getDosesAdministered() const { return DosesAdministered; }  
};

void server(int read_from_pipe, int write_to_pipe) {
    int doses[100];
    int num_vaccines;

    read(read_from_pipe, &num_vaccines, sizeof(num_vaccines));

    read(read_from_pipe, doses, sizeof(int) * num_vaccines);

    int sum = 0;
    for (int i = 0; i < num_vaccines; ++i) {
        sum += doses[i];
    }

    write(write_to_pipe, &sum, sizeof(sum));
}

void client(vector<Vaccination>& vaccinations, int write_to_pipe, int read_from_pipe) {
  
    vaccinations.emplace_back("V001", 3);
    vaccinations.emplace_back("V002", 4);
    vaccinations.emplace_back("V003", 5);
    vaccinations.emplace_back("V004", 6);
    vaccinations.emplace_back("V005", 10);

    int num_vaccines = vaccinations.size();
    int doses[100];

    for (int i = 0; i < num_vaccines; ++i) {
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

    int pipe1[2]; 
    int pipe2[2]; 

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
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
        wait(nullptr);  
    }

    return 0;
}
