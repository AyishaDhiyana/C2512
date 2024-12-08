C++ CODE:

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Employee Hierarchy

class Employee
{
    public:
    //attributes
    string name;
    
    //constructor
    Employee(const string& name) : name(name)
    {
        cout << "Employee constructor called for " << name << endl;
    }
    
    //destructor
    virtual ~Employee()
    {
        cout << "Employee destructor is called for " << name <<endl;
    }
    
    //behaviours
    void work()
    {
        
        cout << name <<" works" << endl;
    }
};

class Manager : virtual public Employee
{
    public:
    //attributes
    string department;
    
    //constructor
    Manager(const string& name, const string& department) : Employee(name), department(department)
    {
        cout << "Manager constructor called for " << department << endl;
    }
    
    //destructor
    virtual ~Manager()
    {
        cout << "Employee destructor is called for " << department <<endl;
    }
    
    //behaviours
    void manage()
    {
        cout << "Manager manages the " << department << "department" << endl;
    }
};

class Engineer : virtual public Employee
{
    public:
    //attributes
    string specialty;
    
    //constructor
    Engineer(const string& name, const string& specialty) : Employee(name), specialty(specialty) 
    {
        cout << "Engineer constructor called for " << specialty << endl;
    }
    
    //destructor
    virtual ~Engineer()
    {
        cout << "Engineer destructor is called for " << specialty <<endl;
    }
    
    //behaviours
    void design()
    {
        cout << "Engineer design solutions specialized in " << specialty << endl;
    }
};

class Teamlead : public Manager, public Engineer
{
    public:
    //attributes
    int teamsize;
    
    //constructor
    Teamlead(const string& name, const string& department, const string& specialty, const int teamsize) : Employee(name), Manager(name, department), Engineer(name, specialty), teamsize(teamsize) 
    {
        cout << "Teamlead constructor called for " << teamsize << endl;
    }
    
    //destructor
    ~Teamlead()
    {
        cout << "Teamlead destructor is called for " << teamsize <<endl;
    }
    
    //behaviours
    void leadTeam()
    {
        cout << "Team leader leads the team of size " << teamsize << endl;
    }
};

int main()
{
    Employee* pemployee = new Teamlead("Ayisha", "Engineering", "AI", 8);
    
    delete pemployee;
    
    return EXIT_SUCCESS;
}

----------------------------------OUTPUT---------------------------------------

Employee constructor called for Ayisha
Manager constructor called for Engineering
Engineer constructor called for AI
Teamlead constructor called for 8
Teamlead destructor is called for 8
Engineer destructor is called for AI
Employee destructor is called for Engineering
Employee destructor is called for Ayisha
