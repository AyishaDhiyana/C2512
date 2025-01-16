== Using TCP socket

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

class Vaccination {
private:
    string VaccinationId;
    int DosesAdministered;

public:
    Vaccination(string p_VaccinationId, int p_DosesAdministered)
        : VaccinationId(p_VaccinationId), DosesAdministered(p_DosesAdministered) {}

    string getVaccinationId() const { return VaccinationId; }
    int getDosesAdministered() const { return DosesAdministered; }
};

void server(int port) {
    int server_fd, client_fd;
    sockaddr_in server_addr{}, client_addr{};
    socklen_t client_len = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        return;
    }

    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        close(server_fd);
        return;
    }

    cout << "Server is listening on port " << port << "..." << endl;

    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("Accept failed");
        close(server_fd);
        return;
    }

    int buffer[102];
    read(client_fd, buffer, sizeof(buffer));

    int num_vaccines = buffer[0];
    int sum = 0;

    for (int i = 1; i <= num_vaccines; ++i) {
        sum += buffer[i];
    }

    write(client_fd, &sum, sizeof(sum));

    close(client_fd);
    close(server_fd);
}

void client(vector<Vaccination>& vaccinations, const char* server_ip, int port) {
    int sockfd;
    sockaddr_in server_addr{};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return;
    }

    vaccinations.emplace_back("V001", 3);
    vaccinations.emplace_back("V002", 4);
    vaccinations.emplace_back("V003", 5);
    vaccinations.emplace_back("V004", 6);
    vaccinations.emplace_back("V005", 10);

    int num_vaccines = vaccinations.size();
    int buffer[102];
    buffer[0] = num_vaccines;

    for (int i = 0; i < num_vaccines; ++i) {
        buffer[i + 1] = vaccinations[i].getDosesAdministered();
    }

    write(sockfd, buffer, sizeof(buffer));

    int sum;
   
    read(sockfd, &sum, sizeof(sum));

    cout << "Sum of doses: " << sum << endl;

    close(sockfd);
}

int main() {
    vector<Vaccination> vaccinations;

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
       
        server(8080);
    } else {
       
        sleep(1); 
        client(vaccinations, "127.0.0.1", 8080);

        wait(nullptr); 
    }

    return 0;
}
