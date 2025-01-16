-Using Message queue

#include <iostream>
#include <string>
#include <vector>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>

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

struct message {
    long msg_type;    
    int data[102];    

void server(int msg_id) {
    message msg;

    msgrcv(msg_id, &msg, sizeof(msg.data), 1, 0);

    int num_vaccines = msg.data[0]; 
    int sum = 0;

    for (int i = 1; i <= num_vaccines; ++i) {
        sum += msg.data[i];
    }

    msg.msg_type = 2; 
    msg.data[0] = sum; 

    msgsnd(msg_id, &msg, sizeof(msg.data), 0);
}

void client(vector<Vaccination>& vaccinations, int msg_id) {
    message msg;
    
    vaccinations.emplace_back("V001", 3);
    vaccinations.emplace_back("V002", 4);
    vaccinations.emplace_back("V003", 5);
    vaccinations.emplace_back("V004", 6);
    vaccinations.emplace_back("V005", 10);

    int num_vaccines = vaccinations.size();
    msg.msg_type = 1; 
    msg.data[0] = num_vaccines; 

    for (int i = 0; i < num_vaccines; ++i) {
        msg.data[i + 1] = vaccinations[i].getDosesAdministered(); 
    }

    msgsnd(msg_id, &msg, sizeof(msg.data), 0);

    msgrcv(msg_id, &msg, sizeof(msg.data), 2, 0);

    cout << "Sum of doses: " << msg.data[0] << endl; 
}

int main() {
    vector<Vaccination> vaccinations;

    int msg_id = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (msg_id == -1) {
        perror("msgget");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        server(msg_id);
    } else {
        client(vaccinations, msg_id);
        wait(nullptr);

        msgctl(msg_id, IPC_RMID, nullptr);
    }

    return 0;
}
