#include <unistd.h> // POSIX
#include <iostream>
const int TIMES = 10;

void parent() {
    for (int i = 1; i < TIMES; i++) {
        std::cout << "Hello parent:" << i << std::endl;
        sleep(1);
    }
}

void child(int id) {
    for (int i = 1; i < TIMES; i++) {
        std::cout << "Hi child" << id << ":" << i << std::endl;
        sleep(1);
    }
}

int main() {
    for (int i = 1; i <= 4; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // This block is executed by the child process
            child(i);
            return 0; // Child exits after its work
        }
    }
    
    // Only the parent reaches here
    parent();
    
    return 0;
}
