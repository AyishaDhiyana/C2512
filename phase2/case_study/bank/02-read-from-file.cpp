#include<fstream>
#include<iostream>
#include<vector>
class BankAccount {
    public:
        double balance;
        int number;
        
        BankAccount(int number, double balance) : number(number), balance(balance) { }
        
        void deserialize_text(std::ifstream& in) {
            in >> this->number;
            in >> this->balance;
        }
        void deserialize_binary_fieldByField(std::ifstream& in) {
            in.read((char*)&number,sizeof(number));
            in.read((char*)&balance,sizeof(balance));
        }
        void deserialize_byObject(std::ifstream& in) {
            in.read((char*)this,sizeof(BankAccount));
        }
        friend std::ostream& operator<<(std::ostream& out, BankAccount& other) {
            out << "[" << other.number << "," << other.balance << "]";
            return out;
        }
};

void deserialize(std::ifstream& in, std::vector<BankAccount>& accounts) {
    in.read((char*)accounts.data(),sizeof(BankAccount)*accounts.size());
}
        
int test1() {
    BankAccount venkyAc(0, 0.0);
    BankAccount vishakAc(0, 0.0);
    std::ifstream in("ac.txt");
    venkyAc.deserialize_text(in);
    vishakAc.deserialize_text(in);
    in.close();
    
    std::cout << venkyAc << std::endl;
    std::cout << vishakAc << std::endl;
}

int test2() {
    BankAccount venkyAc(0, 0.0);
    BankAccount vishakAc(0, 0.0);
    std::ifstream in("acc.dat", std::ios::binary);
    venkyAc.deserialize_binary_fieldByField(in);
    vishakAc.deserialize_binary_fieldByField(in);
    in.close();
    
    std::cout << venkyAc << std::endl;
    std::cout << vishakAc << std::endl;
}

int test3() {
    BankAccount venkyAc(0, 0.0);
    BankAccount vishakAc(0, 0.0);
    std::ifstream in("acc2.dat", std::ios::binary);
    venkyAc.deserialize_byObject(in);
    vishakAc.deserialize_byObject(in);
    in.close();
    
    std::cout << venkyAc << std::endl;
    std::cout << vishakAc << std::endl;
}
int test4() {
    BankAccount venkyAc(0, 0.0);
    BankAccount vishakAc(0, 0.0);
    std::vector<BankAccount> accounts {venkyAc, vishakAc};
    std::ifstream in("acc3.dat", std::ios::binary);
    deserialize(in, accounts);
    in.close();
    
    std::cout << accounts[0] << std::endl;
    std::cout << accounts[1] << std::endl;
}
int main() {
    test1();
    test2();
    test3();
    test4();
}