/**/
// Example for race condition with fix 
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


std::mutex mt;

class BankAccount {
public:
    BankAccount() : balance(0) {}

    void deposit(int amount) {
        
        //int temp = balance; // Read balance
        //std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Simulate work
        //temp += amount; // Update balance
        //balance = temp; // Write back
        
        balance += amount;
    }

    int getBalance() const {
        return balance;
    }

private:
    int balance;
};


void makeDeposits(BankAccount& account) {
    for (int i = 0; i < 1000; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Simulate work
        
        {
            //code 
            std::lock_guard lock(mt);
            account.deposit(1);
        }
        
    }
}

int test() {
    BankAccount account;

    std::thread t1(makeDeposits, std::ref(account));
    std::thread t2(makeDeposits, std::ref(account));

    t1.join();
    t2.join();

    std::cout << "Final balance: " << account.getBalance() << std::endl; // Expected: 2000

    return 0;
}

int main() {
    int t = 15;
    while(t--) {
        test();
    }
    return 0;
}
