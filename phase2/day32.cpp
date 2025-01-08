Resource Management:
RAII -- Resource accusation is initialization.

//without ref -- no thread fn

manual lock and unlock
-- first thread after second thread continues.. (2000)
--------------------------------------------------------
#include <iostream>
#include <thread>
#include <chrono>

class BankAccount 
{
    public:
    BankAccount() : balance(0) {}
    
    void deposit(int amount)
    {
        int temp = balance;
        std::this_thread::sleep_for
        (std::chrono::milliseconds(1));
        temp += amount;
        balance = temp;
    }
    
    int getBalance() const 
    {
        return balance;
    }
    
    private:
    int balance;
};

void makeDeposits(BankAccount& account)
{
    for(int i = 0; i < 1000; ++i)
    {
        account.deposit(1);
    }
}

int main()
{
    BankAccount account;
    
    std::thread t1(makeDeposits, std::ref(account));
    std::thread t2(makeDeposits, std::ref(account));
    
    t1.join();
    t2.join();
    
    std::cout << "Final balance: " << account.getBalance() << std::endl;
    return 0;
}
----------------------------------------------------------------------
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
        mt.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Simulate work
        account.deposit(1);
        mt.unlock();
    }
}

int main() {
    BankAccount account;

    std::thread t1(makeDeposits, std::ref(account));
    std::thread t2(makeDeposits, std::ref(account));

    t1.join();
    t2.join();

    std::cout << "Final balance: " << account.getBalance() << std::endl; // Expected: 2000

    return 0;
}
----LOCK_GUARD is the mutex wrapper
slock--scoped lock
automatically unlock--RAII style
-----------------------------------------------------------------------
use conditional variable via mutex
condition variable-- communication btw threads
-----prog 7----
unique lock used 
lock via mutex
lock until the while condn bcm false.
notify-- notify_one, notify_all.
sleep--chrono library
auto predicate -- 
predicate -- false condition
-----------------------------------------------------------------------

