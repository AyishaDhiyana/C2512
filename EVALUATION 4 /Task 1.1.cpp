#include <iostream>
#include <string>
#include <utility> 
using namespace std;

class Employee {
protected:
    int id;
    int age;
    string name;

public:
    Employee(int id, int age, const string &name) : id(id), age(age), name(name) {}

    friend ostream &operator<<(ostream &os, const Employee &e) {
        os << e.id << " " << e.age << " " << e.name;
        return os;
    }

    void swap(Employee &other) {
        std::swap(id, other.id);
        std::swap(age, other.age);
        std::swap(name, other.name);
    }
};

int main() {
    Employee e1(101, 22, "Athira"), e2(102, 23, "Bhagya");
    cout << e1 << endl;
    cout << e2 << endl;
    e1.swap(e2);
    cout << e1 << endl;
    cout << e2 << endl;

    return 0;
}
