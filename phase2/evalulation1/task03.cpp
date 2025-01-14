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

void findSum(std::vector<Vaccination>& vaccinations, int& write_pipe)
{
    int sum = 0;
	for(int i = 0; i < vaccinations.size(); i++)
    {
        sum = sum + vaccinations[i].getVaccinations();
    }
    write(write_pipe,&sum,sizeof(sum));
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
    if(pid == 0)
    {
        close(pipe_fd[0]);
        findSum(vaccinations,pipe_fd[1]);
        close(pipe_fd[1]);
    }
    else
    {
        close(pipe_fd[1]);
        int sum = 0;
        read(pipe_fd[0], &sum, sizeof(sum));
        close(pipe_fd[0]);

        std::cout << "sum is " << sum << std::endl;
    }
	return 0;
}
