== Named Pipe ==
    
-------------------Client.cpp------------------------
    
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <vector>

using namespace std;

class Vaccination{
	private:
		string vaccinationId;
		int dosesAdministered;
	public:
		Vaccination(string vaccinationId, int dosesAdministered){
			this -> vaccinationId = vaccinationId;
			this -> dosesAdministered = dosesAdministered;
		}

		int getDose(){ return this -> dosesAdministered; };

};

int main(){
	vector<Vaccination> vaccinations;
	vaccinations.emplace_back("V001", 3);
	vaccinations.emplace_back("V002", 2);
	vaccinations.emplace_back("V003", 1);
	vaccinations.emplace_back("V004", 5);
	vaccinations.emplace_back("V005", 4);

	int doses[vaccinations.size()] = {0};
	
	for(int i = 0; i < vaccinations.size(); i++){
		doses[i] = vaccinations[i].getDose();
	}

	
	int numOfElements = vaccinations.size();

	const char* pipe1 = "pipe1";
	const char* pipe2 = "pipe2";
	int pipe_two_read_fd, pipe_one_write_fd;
	pipe_one_write_fd = open(pipe1, O_WRONLY);
	pipe_two_read_fd = open(pipe2, O_RDONLY);
        
	if(pipe_one_write_fd == -1){
		perror("pipe1 open failure at client");
		return 1;
	}
	if(pipe_two_read_fd == -1){
		perror("pipe2 open failure at client");
		return 1;
	}

	write(pipe_one_write_fd, &numOfElements, sizeof(int));
	cout << "Client sent number of elements: " << numOfElements << endl ;

	write(pipe_one_write_fd, doses, sizeof(doses));
	cout << "Client sent doses : ";
	for(int dose:doses){
		cout << dose << "\t";
	}
	cout << endl;
	close(pipe_one_write_fd);

	sleep(1);

	int sum;
	read(pipe_two_read_fd, &sum, sizeof(int));
	cout << "sum received from server: " << sum << endl;

	close(pipe_two_read_fd);
	

	return 0;
}
-----------------makepipe.cpp---------------------
    #include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

int main(){
	const char* pipe1 = "pipe1";
	if(mkfifo(pipe1, 0666) == -1){
		perror("pipe1 failure");
		return 1;
	}
	cout << "pipe1 created successfully" << endl;
	
	const char* pipe2 = "pipe2";
	if(mkfifo(pipe2, 0666) == -1){
		perror("pipe2 failure");
		return 1;
	}
	cout << "pipe2 created successfully" << endl;

	return 0;
}

------------------server.cpp--------------------
    #include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>

using namespace std;

int findSum(int array[], int size){
	int sum = 0;
	for(int i = 0; i < size; i++){
		sum += array[i];
	}
	return sum;
}

int main(){
	const char* pipe1 = "pipe1";
	const char* pipe2 = "pipe2";
	int pipe_one_read_fd, pipe_two_write_fd;
	pipe_one_read_fd = open(pipe1, O_RDONLY);
	pipe_two_write_fd = open(pipe2, O_WRONLY);
	if(pipe_one_read_fd == -1){
		perror("pipe1 open failure");
		return 1;
	}	
	
	if(pipe_two_write_fd == -1){
		perror("pipe2 open failure");
		return 1;
	}

	int numOfElements;
	read(pipe_one_read_fd, &numOfElements, sizeof(int));
	cout << "Server received number of elements: "<< numOfElements << endl ;
	
	int doses[numOfElements] = {0};
	read(pipe_one_read_fd, doses, sizeof(int) * numOfElements);
	cout << "Server received doses: ";
	for(int dose : doses){
		cout << dose << "\t";
	}
	cout << endl;
	close(pipe_one_read_fd);
	
	int sum = findSum(doses, numOfElements);
	write(pipe_two_write_fd, &sum, sizeof(int));
	cout << "Sum sent from server: " << sum << endl;

	close(pipe_two_write_fd);
	return 0;
}
