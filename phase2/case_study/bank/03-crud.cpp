#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

class BankAccount {
private:
    double balance;
    int number;
    std::string name;
    bool active;
    int transCount;

public:
    BankAccount(double bal = 0.0, int num = 0, const std::string& nm = "", bool act = true, int tc = 0)
        : balance(bal), number(num), name(nm), active(act), transCount(tc) {}

    // Getters
    double getBalance() const { return balance; }
    int getNumber() const { return number; }
    std::string getName() const { return name; }
    bool isActive() const { return active; }
    int getTransCount() const { return transCount; }

    // Setters
    void setBalance(double bal) { balance = bal; }
    void setNumber(int num) { number = num; }
    void setName(const std::string& nm) { name = nm; }
    void setActive(bool act) { active = act; }
    void setTransCount(int tc) { transCount = tc; }
};

class FileBankAccount {
public:
    double balance;
    int number;
    char name[255];
    bool active;
    int transCount;

public:
    // Default constructor
    FileBankAccount() : balance(0.0), number(0), active(true), transCount(0) {
        std::memset(name, 0, sizeof(name));
    }

    // Friend functions for conversion
    friend FileBankAccount toFileBankAccount(const BankAccount& account);
    friend BankAccount toBankAccount(const FileBankAccount& fileAccount);
};

// Convert BankAccount to FileBankAccount
FileBankAccount toFileBankAccount(const BankAccount& account) {
    FileBankAccount fileAccount;
    fileAccount.balance = account.getBalance();
    fileAccount.number = account.getNumber();
    std::strncpy(fileAccount.name, account.getName().c_str(), sizeof(fileAccount.name) - 1);
    fileAccount.name[sizeof(fileAccount.name) - 1] = '\0'; // Null-terminate
    fileAccount.active = account.isActive();
    fileAccount.transCount = account.getTransCount();
    return fileAccount;
}

// Convert FileBankAccount to BankAccount
BankAccount toBankAccount(const FileBankAccount& fileAccount) {
    return BankAccount(
        fileAccount.balance,
        fileAccount.number,
        std::string(fileAccount.name),
        fileAccount.active,
        fileAccount.transCount
    );
}

class BankAccountRepo {
private:
    const std::string fileName = "account.dat";

public:
    void create(const BankAccount& account) {
        std::ofstream file(fileName, std::ios::binary | std::ios::app);
        if (!file) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        FileBankAccount fileAccount = toFileBankAccount(account);
        file.write(reinterpret_cast<const char*>(&fileAccount), sizeof(FileBankAccount));
        file.close();
    }

    void update(int id, const BankAccount& account) {
        std::fstream file(fileName, std::ios::binary | std::ios::in | std::ios::out);
        if (!file) {
            throw std::runtime_error("Failed to open file for updating.");
        }

        FileBankAccount fileAccount = toFileBankAccount(account);
        FileBankAccount temp;
        bool updated = false;

        while (file.read(reinterpret_cast<char*>(&temp), sizeof(FileBankAccount))) {
            if (temp.number == id) {
                file.seekp(-static_cast<int>(sizeof(FileBankAccount)), std::ios::cur);
                file.write(reinterpret_cast<const char*>(&fileAccount), sizeof(FileBankAccount));
                updated = true;
                break;
            }
        }

        file.close();
        if (!updated) {
            throw std::runtime_error("Account with given ID not found.");
        }
    }

    void deleteById(int id) {
        std::ifstream file(fileName, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        std::ofstream tempFile("temp.dat", std::ios::binary);
        if (!tempFile) {
            throw std::runtime_error("Failed to open temporary file for writing.");
        }

        FileBankAccount temp;
        bool found = false;

        while (file.read(reinterpret_cast<char*>(&temp), sizeof(FileBankAccount))) {
            if (temp.number != id) {
                tempFile.write(reinterpret_cast<const char*>(&temp), sizeof(FileBankAccount));
            } else {
                found = true;
            }
        }

        file.close();
        tempFile.close();

        if (!found) {
            throw std::runtime_error("Account with given ID not found.");
        }

        std::remove(fileName.c_str());
        std::rename("temp.dat", fileName.c_str());
    }

    std::vector<BankAccount> readAll() {
        std::ifstream file(fileName, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        std::vector<BankAccount> accounts;
        FileBankAccount temp;

        while (file.read(reinterpret_cast<char*>(&temp), sizeof(FileBankAccount))) {
            accounts.push_back(toBankAccount(temp));
        }

        file.close();
        return accounts;
    }

    BankAccount readById(int id) {
        std::ifstream file(fileName, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        FileBankAccount temp;

        while (file.read(reinterpret_cast<char*>(&temp), sizeof(FileBankAccount))) {
            if (temp.number == id) {
                file.close();
                return toBankAccount(temp);
            }
        }

        file.close();
        throw std::runtime_error("Account with given ID not found.");
    }
};

int main() {
    BankAccountRepo repo;

    // Create accounts
    repo.create(BankAccount(5000, 1, "Alice", true, 0));
    repo.create(BankAccount(3000, 2, "Bob", true, 0));
    repo.create(BankAccount(7000, 3, "Charlie", false, 0));

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
    repo.update(2, BankAccount(4000, 2, "Bob Updated", true, 0));

    // Read by ID
    std::cout << "\nAccount with ID 2:" << std::endl;
    BankAccount account = repo.readById(2);
    std::cout << "Account Number: " << account.getNumber()
              << ", Name: " << account.getName()
              << ", Balance: " << account.getBalance()
              << ", Active: " << (account.isActive() ? "Yes" : "No")
              << ", Transactions: " << account.getTransCount() << std::endl;

    // Delete an account
    repo.deleteById(1);

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
