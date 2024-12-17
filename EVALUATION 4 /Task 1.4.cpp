#include <iostream>
#include <string>
#include <memory> 
#include <utility> 
using namespace std;

class Employee {
protected:
    int id;
    int age;
    string name;

public:
    Employee(int id, int age, const string &name) : id(id), age(age), name(name) {}

    virtual ~Employee() {} 

    friend ostream &operator<<(ostream &os, const Employee &e) {
        os << e.id << " " << e.age << " " << e.name;
        return os;
    }

    friend istream &operator>>(istream &is, Employee &e) {
        is >> e.id >> e.age >> e.name;
        return is;
    }

    void swap(Employee &other) {
        std::swap(id, other.id);
        std::swap(age, other.age);
        std::swap(name, other.name);
    }
};

class Programmer : public Employee {
private:
    unique_ptr<string[]> tasks; 
    int taskCount;

public:
    Programmer(int id, int age, const string &name, int taskCount, const string *taskList)
        : Employee(id, age, name), taskCount(taskCount) {
        tasks = make_unique<string[]>(taskCount);
        for (int i = 0; i < taskCount; ++i) {
            tasks[i] = taskList[i];
        }
    }

    Programmer(const Programmer &other) : Employee(other.id, other.age, other.name), taskCount(other.taskCount) {
        tasks = make_unique<string[]>(taskCount);
        for (int i = 0; i < taskCount; ++i) {
            tasks[i] = other.tasks[i];
        }
    }

    Programmer &operator=(const Programmer &other) {
        if (this != &other) {
            Employee::operator=(other); 
            taskCount = other.taskCount;
            tasks = make_unique<string[]>(taskCount);
            for (int i = 0; i < taskCount; ++i) {
                tasks[i] = other.tasks[i];
            }
        }
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Programmer &p) {
        os << static_cast<const Employee &>(p) << " [Tasks: ";
        for (int i = 0; i < p.taskCount; ++i) {
            os << p.tasks[i];
            if (i < p.taskCount - 1) os << ", ";
        }
        os << "]";
        return os;
    }

    friend istream &operator>>(istream &is, Programmer &p) {
        is >> static_cast<Employee &>(p);
        is >> p.taskCount;
        p.tasks = make_unique<string[]>(p.taskCount);
        for (int i = 0; i < p.taskCount; ++i) {
            is >> p.tasks[i];
        }
        return is;
    }

    void swap(Programmer &other) {
        Employee::swap(other);
        std::swap(tasks, other.tasks);
        std::swap(taskCount, other.taskCount);
    }
};

int main() {
   
    string taskList1[] = {"Debugging", "Testing"};
    string taskList2[] = {"Development", "Code Review", "Documentation"};

    Programmer p1(301, 28, "Dev1", 2, taskList1);
    Programmer p2(302, 29, "Dev2", 3, taskList2);

    cout << "Before Swap:" << endl;
    cout << p1 << endl;
    cout << p2 << endl;

    p1.swap(p2);

    cout << "\nAfter Swap:" << endl;
    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}
