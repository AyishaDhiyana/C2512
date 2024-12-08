============================================================
                    PROBLEM STATEMENT 
============================================================

  
Examples for diamond problem in inheritance:
============================================================
These class structures represent the diamond problem,
where the `final derived class` 
inherits ambiguously 
from two intermediate classes 
that share a common base class.
============================================================
Create one static object for final-derived class
and call all behaviours
and 
one dynamic object for final-derived class 
and call all behaviours

Define constructors and destructors for all the classes 

==========================================
                SOLUTION
==========================================
  
C++ CODE :
  
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
    ~Employee()
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
    ~Manager()
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
    ~Engineer()
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
    Teamlead team("Ayisha", "Engineering", "AI", 8);
    
    //methods from Employee,Manager,Engineer
    team.work();
    team.manage();
    team.design();
    team.leadTeam();
    
    return EXIT_SUCCESS;
}

---------------------------OUTPUT----------------------------
  
Employee constructor called for Ayisha
Manager constructor called for Engineering
Engineer constructor called for AI
Teamlead constructor called for 8
Ayisha works
Manager manages the Engineeringdepartment
Engineer design solutions specialized in AI
Team leader leads the team of size 8
Teamlead destructor is called for 8
Engineer destructor is called for AI
Employee destructor is called for Engineering
Employee destructor is called for Ayisha









  
