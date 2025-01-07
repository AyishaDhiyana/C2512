#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class BankAccount {
private:
    double balance;
    int number;
    std::string name; //char name[255]
    bool active;
    int transCount;

public:
    BankAccount() : balance(0), number(0), name(""), active(false), transCount(0) {}
    BankAccount(int number, const std::string& name, double balance, bool active)
        : number(number), name(name), balance(balance), active(active), transCount(0) {}

    // Accessors and Mutators
    int getNumber() const { return number; }
    std::string getName() const { return name; }
    double getBalance() const { return balance; }
    bool isActive() const { return active; }
    int getTransCount() const { return transCount; }

    void setNumber(int num) { number = num; }
    void setName(const std::string& n) { name = n; }
    void setBalance(double b) { balance = b; }
    void setActive(bool a) { active = a; }
    void setTransCount(int count) { transCount = count; }

    // Methods
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transCount++;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            transCount++;
            return true;
        }
        return false;
    }

    // Serialize and Deserialize for binary file
    void serialize(std::ofstream& out) const {
        size_t nameSize = name.size();
        out.write(reinterpret_cast<const char*>(&number), sizeof(number));
        out.write(reinterpret_cast<const char*>(&balance), sizeof(balance));
        out.write(reinterpret_cast<const char*>(&active), sizeof(active));
        out.write(reinterpret_cast<const char*>(&transCount), sizeof(transCount));
        out.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
        out.write(name.c_str(), nameSize);
    }

    void deserialize(std::ifstream& in) {
        size_t nameSize;
        in.read(reinterpret_cast<char*>(&number), sizeof(number));
        in.read(reinterpret_cast<char*>(&balance), sizeof(balance));
        in.read(reinterpret_cast<char*>(&active), sizeof(active));
        in.read(reinterpret_cast<char*>(&transCount), sizeof(transCount));
        in.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        name.resize(nameSize);
        in.read(&name[0], nameSize);
    }
};

class BankAccountRepo {
private:
    const std::string filename = "account.dat";

public:
    void create(const BankAccount& account) {
        std::ofstream out(filename, std::ios::binary | std::ios::app);
        if (!out) {
            std::cerr << "Error opening file for writing!" << std::endl;
            return;
        }
        account.serialize(out);
        out.close();
    }

    void update(int id, const BankAccount& updatedAccount) {
        std::vector<BankAccount> accounts = readAll();
        std::ofstream out(filename, std::ios::binary | std::ios::trunc);
        if (!out) {
            std::cerr << "Error opening file for writing!" << std::endl;
            return;
        }
        for (auto& account : accounts) {
            if (account.getNumber() == id) {
                account = updatedAccount;
            }
            account.serialize(out);
        }
        //out.write(accounts.data(),sizeof(BankAccount)*accounts.size());
        out.close();
    }

    void deleteById(int id) {
        std::vector<BankAccount> accounts = readAll();
        std::ofstream out(filename, std::ios::binary | std::ios::trunc);
        if (!out) {
            std::cerr << "Error opening file for writing!" << std::endl;
            return;
        }
        for (auto& account : accounts) {
            if (account.getNumber() != id) {
                account.serialize(out);
            }
        }
        //BankAccount* data = accounts.data();
        //out.write(data, sizeof(BankAccount)*2);
        //out.write(data+3, sizeof(BankAccount)*accounts.size()-3);
        out.close();
        
    }

    std::vector<BankAccount> readAll() {
        std::vector<BankAccount> accounts;
        std::ifstream in(filename, std::ios::binary);
        if (!in) {
            std::cerr << "Error opening file for reading!" << std::endl;
            return accounts;
        }
        while (in.peek() != EOF) {
            BankAccount account;
            account.deserialize(in);
            accounts.push_back(account);
        }
        in.close();
        return accounts;
    }

    BankAccount readById(int id) {
        std::ifstream in(filename, std::ios::binary);
        if (!in) {
            std::cerr << "Error opening file for reading!" << std::endl;
            return BankAccount();
        }
        while (in.peek() != EOF) {
            BankAccount account;
            account.deserialize(in);
            if (account.getNumber() == id) {
                in.close();
                return account;
            }
        }
        in.close();
        std::cerr << "Account not found!" << std::endl;
        return BankAccount();
    }
};

int main() {
    BankAccountRepo repo;

    // Create accounts
    repo.create(BankAccount(1, "Alice", 5000, true));   //4+(8+5)+8+1+4 = 30        = 4 + 255 + 8 + 1 + 4 = 300
    repo.create(BankAccount(2, "Bob", 3000, true));     //4+(8+3)+8+1+4 = 28 = 58   =                       
    repo.create(BankAccount(3, "Charlie", 7000, false));//4+(8+7)+8+1+4 = 32 = 90                         = 900

    // Read all accounts
    std::cout << "All Accounts:" << std::endl;
    for (const auto& account : repo.readAll()) {
        std::cout << "Account Number: " << account.getNumber()
                  << ", Name: " << account.getName()
                  << ", Balance: " << account.getBalance()
                  << ", Active: " << (account.isActive() ? "Yes" : "No")
                  << ", Transactions: " << account.getTransCount() << std::endl;
    }

    // Update an account
    repo.update(2, BankAccount(2, "Bob Updated", 4000, true));//4+(8+11)+8+1+4 = 36 +8 = 98

    // Read by ID
    std::cout << "\nAccount with ID 2:" << std::endl;
    BankAccount account = repo.readById(2);
    std::cout << "Account Number: " << account.getNumber()
              << ", Name: " << account.getName()
              << ", Balance: " << account.getBalance()
              << ", Active: " << (account.isActive() ? "Yes" : "No")
              << ", Transactions: " << account.getTransCount() << std::endl;

    // Delete an account
    repo.deleteById(1);                                     // 68

    // Read all accounts after deletion
    std::cout << "\nAll Accounts after deletion:" << std::endl;
    for (const auto& acc : repo.readAll()) {
        std::cout << "Account Number: " << acc.getNumber()
                  << ", Name: " << acc.getName()
                  << ", Balance: " << acc.getBalance()
                  << ", Active: " << (acc.isActive() ? "Yes" : "No")
                  << ", Transactions: " << acc.getTransCount() << std::endl;
    }

    return 0;
}