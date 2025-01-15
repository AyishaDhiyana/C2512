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

    int getVaccinations() {
        return DosesAdministered;
    }
};

void server(int read_from_pipe, int write_to_pipe) {
    int doses[100];
    int num_vaccines;

    // Read the number of vaccination records from the pipe
    read(read_from_pipe, &num_vaccines, sizeof(num_vaccines));

    // Read the doses array from the pipe
    read(read_from_pipe, doses, sizeof(int) * num_vaccines);

    // Calculate the sum
    int sum = 0;
    for (int i = 0; i < num_vaccines; ++i) {
        sum += doses[i];
    }

    // Send the calculated sum back to the client
    write(write_to_pipe, &sum, sizeof(sum));
}

void client(vector<Vaccination>& vaccinations, int write_to_pipe, int read_from_pipe) {
    // Add vaccination data using emplace_back
    vaccinations.emplace_back("V001", 3);
    vaccinations.emplace_back("V002", 4);
    vaccinations.emplace_back("V003", 5);
    vaccinations.emplace_back("V004", 6);
    vaccinations.emplace_back("V005", 10);

    int num_vaccines = vaccinations.size();
    int doses[100];

    // Fill the doses array with data
    for (int i = 0; i < num_vaccines; ++i) {
        doses[i] = vaccinations[i].getVaccinations();
    }

    // Send the number of vaccinations to the server
    write(write_to_pipe, &num_vaccines, sizeof(num_vaccines));

    // Send the doses array to the server
    write(write_to_pipe, doses, sizeof(int) * num_vaccines);

    // Read the sum from the server
    int sum;
    read(read_from_pipe, &sum, sizeof(sum));

    // Print the final result
    cout << "Sum of doses: " << sum << endl;
}

int main() {
    vector<Vaccination> vaccinations;

    int pipe1[2]; // Pipe for client to send data to the server
    int pipe2[2]; // Pipe for server to send data back to the client

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        return 1; // Exit if pipe creation fails
    }

    pid_t pid = fork();
    if (pid == -1) {
        return 1; // Exit if fork fails
    }

    if (pid == 0) {
        // Child process - Server
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2
        server(pipe1[0], pipe2[1]);
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2
    } else {
        // Parent process - Client
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2
        client(vaccinations, pipe1[1], pipe2[0]);
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2
        wait(nullptr);   // Wait for the child process to finish
    }

    return 0;
}