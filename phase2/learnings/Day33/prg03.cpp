/**/
// Example for race condition with fix 
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>


class BankAccount {
public:
    BankAccount() : balance(0) {}

    void deposit(int amount) {
        //balance += amount;
        balance.fetch_add(amount);
    }

    int getBalance() const {
        return balance.load();
    }

private:
    std::atomic<int> balance;
    //std::atomic_int balance;
};


void makeDeposits(BankAccount& account) {
    for (int i = 0; i < 1000; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Simulate work
        
        account.deposit(1);
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
