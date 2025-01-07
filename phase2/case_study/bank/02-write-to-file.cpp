#include<fstream>
#include<iostream>
#include<vector>
class BankAccount {
    public:
        double balance;
        int number;
        
        BankAccount(int number, double balance) : number(number), balance(balance) { }
        
        void serialize_text(std::ofstream& out) {
            out << this->number << std::endl;
            out << this->balance << std::endl;
        }
        void serialize_binary_fieldByField(std::ofstream& out) {
            out.write((const char*)&number,sizeof(number));
            out.write((const char*)&balance,sizeof(balance));
        }
        void serialize_byObject(std::ofstream& out) {
            out.write((const char*)this,sizeof(BankAccount));
        }
        
};

void serialize(std::ofstream& out, std::vector<BankAccount>& accounts) {
    out.write((const char*)accounts.data(),sizeof(BankAccount)*accounts.size());
}
        
int test1() {
    BankAccount venkyAc(101, 2000.0);
    BankAccount vishakAc(102, 2001.0);
    std::ofstream out("ac.txt", std::ios::app);
    venkyAc.serialize_text(out);
    vishakAc.serialize_text(out);
    out.close();
}

int test2() {
    BankAccount venkyAc(101, 2000.0);
    BankAccount vishakAc(102, 2001.0);
    std::ofstream out("acc.dat", std::ios::binary | std::ios::app);
    venkyAc.serialize_binary_fieldByField(out);
    vishakAc.serialize_binary_fieldByField(out);
    out.close();
}

int test3() {
    BankAccount venkyAc(101, 2000.0);
    BankAccount vishakAc(102, 2001.0);
    std::ofstream out("acc2.dat", std::ios::binary | std::ios::app);
    venkyAc.serialize_byObject(out);
    vishakAc.serialize_byObject(out);
    out.close();
}
int test4() {
    BankAccount venkyAc(101, 2000.0);
    BankAccount vishakAc(102, 2001.0);
    std::vector<BankAccount> accounts {venkyAc, vishakAc};
    std::ofstream out("acc3.dat", std::ios::binary | std::ios::app);
    serialize(out, accounts);
    out.close();
}
int main() {
    test1();
    test2();
    test3();
    test4();
}
