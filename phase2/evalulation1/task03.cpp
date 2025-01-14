#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <climits>

using namespace std;

class Vaccination
{
	private:
	std::string VaccinationId;
	int DosesAdministered;
	
	public:
	Vaccination(std::string p_VaccinationId, int p_DosesAdministered) : VaccinationId(p_VaccinationId), DosesAdministered(p_DosesAdministered) {}
    int getVaccinations() 
    { 
        return DosesAdministered;
    }   
};

void server(std::vector<Vaccination>& vaccinations, int& write_end_fd)
{
    int sum = 0;
	for(int i = 0; i < vaccinations.size(); i++)
    {
        sum = sum + vaccinations[i].getVaccinations();
    }
    write(write_end_fd,&sum,sizeof(sum));
    cout << "server sent sum " << sum << endl;
}

void client(int read_end_fd)
{
    int sum = 0;
    read(read_end_fd, &sum, sizeof(sum));
    std::cout << "Sum of doses " << sum << std::endl;
    cout << "client received" << endl;
}
int main()
{
	std::vector<Vaccination> vaccinations;
    vaccinations.emplace_back("V001", 3);
    vaccinations.emplace_back("V002", 4);
    vaccinations.emplace_back("V003", 5);
    vaccinations.emplace_back("V004", 6);
    vaccinations.emplace_back("V005", 10);

    int pipe_fd[2];
    if(pipe(pipe_fd) == -1)
    {
        perror("pipe");
        return 1;
    }
    pid_t pid = fork();
    //child process
    if(pid == 0)
    {
        close(pipe_fd[0]);
        server(vaccinations,pipe_fd[1]);
        close(pipe_fd[1]);
    }
    else
    {
        close(pipe_fd[1]);
        client(pipe_fd[0]);
        close(pipe_fd[0]);
    }
	return 0;
}

----
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>

class Doctor {
private:
    std::string doctorId;
    int yearOfExperience;
public:
    Doctor(std::string id, int experience) : doctorId(id), yearOfExperience(experience) {}
    int getYearOfExperience() const { return yearOfExperience; }
};

int sum(const std::vector<Doctor>& exp) {
    int res = 0;
    for (const auto& doc : exp) {
        res += doc.getYearOfExperience();
    }
    return res;
}

void client(int write_fd, int read_fd, const std::vector<Doctor>& doctors) {
    // Serialize the vector data
    int size = doctors.size();
    write(write_fd, &size, sizeof(size)); // Send vector size

    for (const auto& doc : doctors) {
        int experience = doc.getYearOfExperience();
        write(write_fd, &experience, sizeof(experience)); // Send each doctor's experience
    }

    close(write_fd); // Close the write end after sending

    // Read the result from the server
    int result;
    read(read_fd, &result, sizeof(result));
    close(read_fd); // Close the read end after reading

    std::cout << "Sum of years of experience received from server: " << result << std::endl;
}

void server(int read_fd, int write_fd) {
    // Read the vector size
    int size;
    read(read_fd, &size, sizeof(size));

    // Deserialize the vector data
    std::vector<Doctor> doctors;
    for (int i = 0; i < size; ++i) {
        int experience;
        read(read_fd, &experience, sizeof(experience));
        doctors.emplace_back("D" + std::to_string(i + 1), experience); // Create Doctor objects
    }

    // Calculate the sum
    int result = sum(doctors);

    // Send the result back to the client
    write(write_fd, &result, sizeof(result));

    close(read_fd); // Close the read end after reading
    close(write_fd); // Close the write end after sending
}

int main() {
    int pipe_client_to_server[2]; // Pipe for client to server
    int pipe_server_to_client[2]; // Pipe for server to client

    if (pipe(pipe_client_to_server) == -1 || pipe(pipe_server_to_client) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process - Server
        close(pipe_client_to_server[1]); // Close write end of client-to-server pipe
        close(pipe_server_to_client[0]); // Close read end of server-to-client pipe
        server(pipe_client_to_server[0], pipe_server_to_client[1]); // Process data
        return 0;
    } else {
        // Parent process - Client
        close(pipe_client_to_server[0]); // Close read end of client-to-server pipe
        close(pipe_server_to_client[1]); // Close write end of server-to-client pipe

        std::vector<Doctor> doctors = {
            Doctor("D001", 1),
            Doctor("D002", 2),
            Doctor("D003", 3),
            Doctor("D004", 4),
            Doctor("D005", 5)
        };

        client(pipe_client_to_server[1], pipe_server_to_client[0], doctors); // Send data and read result
        wait(nullptr); // Wait for the child process to finish
    }

    return 0;
}