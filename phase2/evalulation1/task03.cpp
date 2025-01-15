#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

// Vaccination Class
class Vaccination {
private:
    string VaccinationId;
    int DosesAdministered;

public:
    Vaccination(string p_VaccinationId, int p_DosesAdministered)
        : VaccinationId(p_VaccinationId), DosesAdministered(p_DosesAdministered) {}

    int getVaccinations() { 
        return DosesAdministered; 
    }
};

// Server Function
void server(vector<Vaccination>& vaccinations, int write_to_pipe) {
    int sum = 0;
    // Calculate the sum of doses
    for (const auto& vaccination : vaccinations) {
        sum += vaccination.getVaccinations();
    }
    // Write the sum to the pipe
    write(write_to_pipe, &sum, sizeof(sum));
    cout << "Server: Sent the sum to the client." << endl;
}

// Client Function
void client(int read_from_pipe) {
    int sum = 0;
    // Read the sum from the pipe
    read(read_from_pipe, &sum, sizeof(sum));
    cout << "Client: Received sum of doses = " << sum << endl;
}

int main() {
    vector<Vaccination> vaccinations = {
        {"V001", 3},
        {"V002", 4},
        {"V003", 5},
        {"V004", 6},
        {"V005", 10}
    };
    // Create two pipes for communication
    int pipe1[2]; // Used by server to send data to client
    int pipe2[2]; // Used by client to acknowledge receipt (optional)

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) { // Child process: Server
        close(pipe1[0]); // Close unused read end of pipe1
        close(pipe2[1]); // Close unused write end of pipe2

        server(vaccinations, pipe1[1]);

        close(pipe1[1]); // Close write end of pipe1 after sending
        close(pipe2[0]); // Close read end of pipe2 (not used)
    } else { // Parent process: Client
        close(pipe1[1]); // Close unused write end of pipe1
        close(pipe2[0]); // Close unused read end of pipe2

        client(pipe1[0]);

        close(pipe1[0]); // Close read end of pipe1 after reading
        close(pipe2[1]); // Close write end of pipe2 (not used)

        wait(nullptr); // Wait for the server process to finish
    }

    return 0;
}
