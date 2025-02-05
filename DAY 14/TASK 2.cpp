Problem Statement: `Employee Salary Management System`

`Objective`:  
You need to develop a C++ program that performs the following tasks:

1. `Input an Array of Salaries`:
   - The program should take input for the salaries of `10 employees` 
   (you can modify the number as required).
   - The program should store these salaries in an array.


void readSalaries(int salary[], int& size) {
    int salaries;
    size = 0;

    cout << "Enter salaries: " << endl;
    while (size < MAX_SALARY) {
        cout << "Enter salary " << size + 1 << ": ";
        cin >> salaries;
        if (salaries < 0) {
            cout << "Enter valid salary" << endl;
            continue;
        }
        salary[size] = salaries;
        size++;
    }
    cout << "Max salary reached" << endl;
}
------------------------------------------------------------------------

2. `Find the Second Highest Salary`:
   - Implement a function to find the second highest salary in the array.

int secondMaxSalary(int salary[], int size) {
    int maxsalary = INT_MIN;
    int secondMaxSalary = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (salary[i] > maxsalary) {
            secondMaxSalary = maxsalary;
            maxsalary = salary[i];
        } else if (salary[i] > secondMaxSalary && salary[i] < maxsalary) {
            secondMaxSalary = salary[i];
        }
    }
    return secondMaxSalary;
}
----------------------------------------------------------------------------

3. `Check if the Second Highest Salary is Exactly 5 Digits`:
   - After identifying the second highest salary, 
   check whether the salary is a 5-digit number (between 10000 and 99999).
   - Print a message indicating 
   whether the second highest salary is 5 digits or not.

bool is5digits(int number) {
    return (number >= 10000 && number <= 99999);
}
-------------------------------------------------------------------------------

4. `Print All Salaries`:
   - Implement a function 
   to print all employee salaries stored in the array.

void PrintAllSalaries(int salary[], int size) {
    cout << "Salaries are: ";
    for (int i = 0; i < size; i++) {
        cout << salary[i] << endl;
    }
    cout << endl;
}

---------------------------------------------------
SOLUTION
---------------------------------------------------
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ mkdir Employee_salary_management_system
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~$ cd Employee_salary_management_system
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/Employee_salary_management_system$ touch emp_salary.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/Employee_salary_management_system$ ls
emp_salary.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/Employee_salary_management_system$ vi emp_salary.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/Employee_salary_management_system$ cat emp_salary.cpp
#include <iostream>
#include <cstdlib>
#include <climits> 

using std::cin;
using std::cout;
using std::endl;

const int MAX_SALARY = 10;

void readSalaries(int salary[], int& size) {
    int salaries;
    size = 0;

    cout << "Enter salaries: " << endl;
    while (size < MAX_SALARY) {
        cout << "Enter salary " << size + 1 << ": ";
        cin >> salaries;
        if (salaries < 0) {
            cout << "Enter valid salary" << endl;
            break;
        }
        salary[size] = salaries;
        size++;
    }
    cout << "Max salary reached" << endl;
}

int secondMaxSalary(int salary[], int size) {
    int maxsalary = INT_MIN;
    int secondMaxSalary = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (salary[i] > maxsalary) {
            secondMaxSalary = maxsalary;
            maxsalary = salary[i];
        } else if (salary[i] > secondMaxSalary && salary[i] < maxsalary) {
            secondMaxSalary = salary[i];
        }
    }
    return secondMaxSalary;
}

bool is5digits(int number) {
    return (number >= 10000 && number <= 99999);
}

void PrintAllSalaries(int salary[], int size) {
    cout << "Salaries are: ";
    for (int i = 0; i < size; i++) {
        cout << salary[i] << endl;
    }
    cout << endl;
}

void test(void) {
    int salary[MAX_SALARY];
    int size;

    readSalaries(salary, size);
    PrintAllSalaries(salary, size);

    int second_max_salary = secondMaxSalary(salary, size);
    cout << "Second max salary is " << second_max_salary << endl;

    if (is5digits(second_max_salary)) {
        cout << "Second max salary is a 5-digit number: " << second_max_salary << endl;
    }
   else
    {
        cout << "Second Max salary is not 5 digits " << endl;
    }
}

int main(void) {
    test();
    return EXIT_SUCCESS;
}
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/Employee_salary_management_system$ vi emp_salary.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/Employee_salary_management_systayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/Employee_salary_management_system$ g++ emp_salary.cpp
ayisha-dhiyana-ps@ayisha-dhiyana-ps-VirtualBox:~/Employee_salary_management_system$ ./a.out
Enter salaries: 
Enter salary 1: 10000
Enter salary 2: 20000
Enter salary 3: 30000
Enter salary 4: 40000
Enter salary 5: 55000
Enter salary 6: 80000
Enter salary 7: 56000
Enter salary 8: 67777
Enter salary 9: 80990
Enter salary 10: 50000
Max salary reached
Salaries are: 10000 20000 30000 40000 55000 80000 56000 67777 80990 50000 
Second max salary is 80000
Second max salary is a 5-digit number: 80000


