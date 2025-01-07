#include <unistd.h> //POSIX
#include <iostream>

const int TIMES = 3;
void parent() {
    //code for parent
    for(int I = 1; I <= TIMES; I++) {
        std::cout << "Hello parent:" << I << std::endl;
        sleep(1);
    }
}
void child(int id) {
    //code for child
    for(int I = 1; I <= TIMES; I++) {
        std::cout << "Hi child" << id << ":" << I << std::endl;
        sleep(1);
    } 
}

int main() {
    {
        pid_t pid1 = fork();
        if(pid1 == 0) {
            child(1);
            return 0;
        } 
    }
    {
        pid_t pid2 = fork();
        if(pid2 == 0) {
            child(2);
            return 0;
        } 
    }
    {
        pid_t pid3 = fork();
        if(pid3 == 0) {
            child(2);
            return 0;
        } 
    }
    {
        pid_t pid4 = fork();
        if(pid4 == 0) {
            child(3);
            return 0;
        } 
    }

    parent();    
    return 0;
}