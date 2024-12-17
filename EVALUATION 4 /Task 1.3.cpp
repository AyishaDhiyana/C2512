//1.3 Programmer { string* tasks; int taskCount; } : Employee | tasks is the multiple tasks - array of task 
        // swap function overloadable
        // here, create the dynamic programmer object assigned to employee pointer.
        // field 'tasks' is dynamic memoery.
        // operator << overloadable, swap is overridden.


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Employee 
{
   public:
       int* id;         
       int* age;         
       string* name; 
   
   public:
       Employee(int e_id, int e_age, string e_name)
       {
           id = new int(e_id);          
           age = new int(e_age);        
           name = new string(e_name);  
       }

    virtual ~Employee() 
    {
        delete id;    
        delete age;   
        delete name; 
    }

    virtual void printDetails()
   {
        cout << *id << " " << *age << " " << *name; 
    }

    virtual void swap(Employee& other)
    {
        std::swap(id, other.id);  
        std::swap(age, other.age);
        std::swap(name, other.name);
    }

    friend ostream& operator<<(ostream& out,Employee& employee);
};


class Programmer : public Employee 
{
   public:
       string* tasks;  
       int taskCount;  
   
   public:
       Programmer(int p_id, int p_age, string p_name, string* p_tasks, int p_taskCount)
           : Employee(p_id, p_age, p_name), taskCount(p_taskCount)
       {
           tasks = new string[taskCount];   
           for (int i = 0; i < taskCount; i++) 
           {
               tasks[i] = p_tasks[i];  
           }
       }

    ~Programmer() 
    {
        delete[] tasks;
    }

    void swap(Programmer& other)
    {
        std::swap(taskCount, other.taskCount);
        std::swap(tasks, other.tasks);
        
        Employee::swap(other);
    }

    void printDetails() override 
    {
        Employee::printDetails(); 
        cout << " Tasks: ";
        for (int i = 0; i < taskCount; i++)
        {
            cout << tasks[i]<<" ";  
        }
    }

    friend ostream& operator<<(ostream& out, Programmer& programmer);
};

ostream& operator<<(ostream& out, Employee& employee) 
{
    employee.printDetails();
    return out; 
}

ostream& operator<<(ostream& out,Programmer& programmer) 
{
    programmer.printDetails();
    return out;  
}

int main() 
{
    string tasks1[] = {"Task10", "Task11", "Task12"};
    Employee* p1 = new Programmer(101, 22, "Athira", tasks1, 3);

    string tasks2[] = {"Task20", "Task21", "Task22"};
    Employee* p2 = new Programmer(102, 23, "Bhagya", tasks2, 3);

    cout << "p1: " << *p1 << endl;  
    cout << "p2: " << *p2 << endl; 

    p1->swap(*p2);

    cout << "after swap" << endl;
    cout << "p1: " << *p1 << endl;  
    cout << "p2: " << *p2 << endl;  

    delete p1;
    delete p2;

    return 0;
}
