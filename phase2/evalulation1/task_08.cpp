== Named Pipe ==
    
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

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

void server(const char* read_fifo, const char* write_fifo) {
    int doses[100];
    int num_vaccines;

    int read_fd = open(read_fifo, O_RDONLY);
    if (read_fd == -1) {
        perror("Error opening read FIFO");
        return;
    }

    read(read_fd, &num_vaccines, sizeof(num_vaccines));
    read(read_fd, doses, sizeof(int) * num_vaccines);

    close(read_fd);

    int sum = 0;
    for (int i = 0; i < num_vaccines; ++i) {
        sum += doses[i];
    }

    int write_fd = open(write_fifo, O_WRONLY);
    if (write_fd == -1) {
        perror("Error opening write FIFO");
        return;
    }

    write(write_fd, &sum, sizeof(sum));
    close(write_fd);
}

void client(vector<Vaccination>& vaccinations, const char* write_fifo, const char* read_fifo) {
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

    int write_fd = open(write_fifo, O_WRONLY);
    if (write_fd == -1) {
        perror("Error opening write FIFO");
        return;
    }

    write(write_fd, &num_vaccines, sizeof(num_vaccines));
    write(write_fd, doses, sizeof(int) * num_vaccines);
    close(write_fd);

    int sum;
    int read_fd = open(read_fifo, O_RDONLY);
    if (read_fd == -1) {
        perror("Error opening read FIFO");
        return;
    }

    read(read_fd, &sum, sizeof(sum));
    close(read_fd);

    cout << "Sum of doses: " << sum << endl;
}

int main() {
    vector<Vaccination> vaccinations;

    const char* fifo1 = "/tmp/fifo1";
    const char* fifo2 = "/tmp/fifo2";

    if (mkfifo(fifo1, 0666) == -1 || mkfifo(fifo2, 0666) == -1) {
        perror("Error creating FIFOs");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Error forking process");
        return 1;
    }

    if (pid == 0) {
        server(fifo1, fifo2);
    } else {
      
        client(vaccinations, fifo1, fifo2);
        wait(nullptr); 
    }

    unlink(fifo1);
    unlink(fifo2);

    return 0;
}
