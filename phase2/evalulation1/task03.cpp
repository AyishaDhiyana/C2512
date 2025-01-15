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
    Vaccination(string p_VaccinationId, int p_DosesAdministered)
        : VaccinationId(p_VaccinationId), DosesAdministered(p_DosesAdministered) {}

    string getVaccinationId() const { return VaccinationId; }
    int getDosesAdministered() const { return DosesAdministered; } 
};

void client(vector<Vaccination>& vaccinations, int write_to_pipe) {
    int sum = 0;
    for (const auto& vaccination : vaccinations) {
        sum += vaccination.getDosesAdministered();
    }
    write(write_to_pipe, &sum, sizeof(sum));
}

void server(int read_from_pipe) {
    int sum = 0;
    read(read_from_pipe, &sum, sizeof(sum));
    std::cout << "Server received sum of doses = " << sum  << " from client "<< std::endl;
}

int main() {
    vector<Vaccination> vaccinations = {
        {"V001", 3},
        {"V002", 4},
        {"V003", 5},
        {"V004", 6},
        {"V005", 10}
    };

    int pipe1[2]; //server-client
    int pipe2[2]; //client-server

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) 
    { 
        close(pipe1[0]); 
        close(pipe2[1]); 

        client(vaccinations, pipe1[1]);

        close(pipe1[1]); 
        close(pipe2[0]); 
    } 
    else
    {    
        close(pipe1[1]); 
        close(pipe2[0]); 

        server(pipe1[0]);

        close(pipe1[0]); 
        close(pipe2[1]); 

        wait(nullptr); 
    }

    return 0;
}
