== Shared memory ==
    
#include <iostream>
#include <string>
#include <vector>
#include <sys/ipc.h>
#include <sys/shm.h>
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
void server(int shm_id) {
    int* shared_memory = (int*)shmat(shm_id, nullptr, 0);

    if (shared_memory == (void*)-1) {
        perror("shmat");
        return;
    }

    int num_vaccines = shared_memory[0]; 
    int sum = 0;

    for (int i = 1; i <= num_vaccines; ++i) {
        sum += shared_memory[i]; 
    }

    shared_memory[num_vaccines + 1] = sum; 
    shmdt(shared_memory); 
}

void client(vector<Vaccination>& vaccinations, int shm_id) {
    int* shared_memory = (int*)shmat(shm_id, nullptr, 0);

    if (shared_memory == (void*)-1) {
        perror("shmat");
        return;
    }

    vaccinations.emplace_back("V001", 3);
    vaccinations.emplace_back("V002", 4);
    vaccinations.emplace_back("V003", 5);
    vaccinations.emplace_back("V004", 6);
    vaccinations.emplace_back("V005", 10);

    int num_vaccines = vaccinations.size();
    shared_memory[0] = num_vaccines; 

    for (int i = 0; i < num_vaccines; ++i) {
        shared_memory[i + 1] = vaccinations[i].getDosesAdministered(); 
    }

    sleep(1);

    cout << "Sum of doses: " << shared_memory[num_vaccines + 1] << endl; 
    shmdt(shared_memory); 
}

int main() {
    vector<Vaccination> vaccinations;

    int shm_id = shmget(IPC_PRIVATE, sizeof(int) * 102, IPC_CREAT | 0666); 
    if (shm_id == -1) {
        perror("shmget");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
    
        server(shm_id);
    } else {
       
        client(vaccinations, shm_id);

        wait(nullptr);

        shmctl(shm_id, IPC_RMID, nullptr);
    }

    return 0;
}
