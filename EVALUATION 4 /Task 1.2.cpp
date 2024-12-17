#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int* id;        // Pointer to dynamically allocated memory for Employee ID
    int* age;       // Pointer to dynamically allocated memory for Employee age
    string* name;   // Pointer to dynamically allocated memory for Employee name

public:
    // Parameterized Constructor
    Employee(int empId, int empAge, const string& empName) {
        id = new int(empId);             // Dynamically allocate memory for id
        age = new int(empAge);           // Dynamically allocate memory for age
        name = new string(empName);      // Dynamically allocate memory for name
    }

    // Destructor to free dynamically allocated memory
    ~Employee() {
        delete id;      // Free memory allocated for id
        delete age;     // Free memory allocated for age
        delete name;    // Free memory allocated for name
    }

    // Move Constructor
    Employee(Employee&& other) noexcept
        : id(other.id), age(other.age), name(std::move(*other.name)) {
        other.id = nullptr;
        other.age = nullptr;
    }

    // Move Assignment Operator
    Employee& operator=(Employee&& other) noexcept {
        if (this != &other) {
            // Move the resources from the other object
            delete id;     // Delete previous dynamically allocated memory
            delete age;    // Delete previous dynamically allocated memory
            delete name;   // Delete previous dynamically allocated memory

            id = other.id;
            age = other.age;
            name = std::move(*other.name);

            // Reset the state of the moved-from object
            other.id = nullptr;
            other.age = nullptr;
        }
        return *this;
    }

    // Overload << operator for displaying Employee details
    friend ostream& operator<<(ostream& os, const Employee& emp) {
        os << *(emp.id) << " " << *(emp.age) << " " << *(emp.name);
        return os;
    }

    // Swap function to swap two Employee objects using move constructor and move assignment
    void swap(Employee& other) {
        // Move current object to temporary
        Employee temp = std::move(*this);  // Move the current object to temp
        
        // Move the other object to the current object
        *this = std::move(other);          // Move the other object to *this
        
        // Move the temporary object to the other object
        other = std::move(temp);           // Move temp to the other object
    }
};

int main() {
    // Creating Employee objects dynamically
    Employee* e1 = new Employee(101, 22, "Athira");
    Employee* e2 = new Employee(102, 23, "Bhagya");

    // Display initial Employee details
    cout << "Before swapping:" << endl;
    cout << *e1 << endl; // 101 22 Athira
    cout << *e2 << endl; // 102 23 Bhagya

    // Swapping Employee objects
    e1->swap(*e2);

    // Display Employee details after swapping
    cout << "After swapping:" << endl;
    cout << *e1 << endl; // 102 23 Bhagya
    cout << *e2 << endl; // 101 22 Athira

    // Free dynamically allocated memory
    delete e1;
    delete e2;

    return 0;
}
