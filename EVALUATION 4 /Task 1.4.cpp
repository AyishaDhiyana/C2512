#include <iostream>
#include <algorithm>
#include <string>
#include <memory>  
using namespace std;

class Employee {
public:
    
    unique_ptr<int> id;         
    unique_ptr<int> age;         
    unique_ptr<string> name; 

public:
    Employee(int v_id, int v_age, string v_name)
        : id(make_unique<int>(v_id)), age(make_unique<int>(v_age)), name(make_unique<string>(v_name)) {}

    virtual void printDetails() const {
        cout << *id << " " << *age << " " << *name; 
    }

    virtual void swap(Employee& other) {
        std::swap(id, other.id);  
        std::swap(age, other.age);
        std::swap(name, other.name);
    }

    friend ostream& operator<<(ostream& os, const Employee& e);
};

class Programmer : public Employee {
public:
    unique_ptr<string[]> tasks;  
    int taskCount;  

public:
    Programmer(int v_id, int v_age, string v_name, string* v_tasks, int v_taskCount)
        : Employee(v_id, v_age, v_name), taskCount(v_taskCount) {
        tasks = make_unique<string[]>(taskCount);   
        for (int i = 0; i < taskCount; i++) {
            tasks[i] = v_tasks[i];  
        }
    }

    void swap(Programmer& other) {
        std::swap(taskCount, other.taskCount);
        std::swap(tasks, other.tasks);

        Employee::swap(other);
    }

    void printDetails() const override {
        Employee::printDetails(); 
        cout << " Tasks: ";
        for (int i = 0; i < taskCount; i++) {
            cout << tasks[i] << " ";  
        }
    }

    friend ostream& operator<<(ostream& os, const Programmer& p);
};

ostream& operator<<(ostream& os, const Employee& e) {
    e.printDetails();
    return os; 
}

ostream& operator<<(ostream& os, const Programmer& p) {
    p.printDetails();
    return os;  
}

int main() {
    // array for Programmer 1
    string tasks1[] = {"Task10", "Task11", "Task12"};
    unique_ptr<Employee> p1 = make_unique<Programmer>(101, 22, "Athira", tasks1, 3);

    // array for Programmer 2
    string tasks2[] = {"Task20", "Task21", "Task22"};
    unique_ptr<Employee> p2 = make_unique<Programmer>(102, 23, "Bhagya", tasks2, 3);

    cout << "p1: " << *p1 << endl;  
    cout << "p2: " << *p2 << endl; 

    p1->swap(*p2);

    cout << "after swap" << endl;
    cout << "p1: " << *p1 << endl;  
    cout << "p2: " << *p2 << endl;  

    return 0;
}
