# 1. Write a Python class Employee with attributes like emp_id, emp_name, emp_salary, and emp_department and methods like calculate_emp_salary, emp_assign_department, and print_employee_details.
# Sample Employee Data:
# "ADAMS", "E7876", 50000, "ACCOUNTING"
# "JONES", "E7499", 45000, "RESEARCH"
# "MARTIN", "E7900", 50000, "SALES"
# "SMITH", "E7698", 55000, "OPERATIONS"

# Use 'assign_department' method to change the department of an employee.
# Use 'print_employee_details' method to print the details of an employee.
# Use 'calculate_emp_salary' method takes two arguments: salary and hours_worked, 
# which is the number of hours worked by the employee. If the number of hours worked is more than 50, 
# the method computes overtime and adds it to the salary. Overtime is calculated as following formula:
# overtime = hours_worked - 50
# Overtime amount = (overtime * (salary / 50))

#Solution

class Employee:

    def __init__(employee, emp_id, emp_name, emp_salary, emp_department):
        employee.emp_id = emp_id
        employee.emp_name = emp_name
        employee.emp_salary = emp_salary
        employee.emp_department = emp_department

    def calculate_emp_salary(self,hours_worked):
        hours_worked = int(input(f"Enter the hours worked by the employee {self.name}: "))

        if hours_worked > 50:
            overtime = hours_worked - 50
            overtime_amount = (overtime * (self.emp_salary / 50))
            total_salary = self.emp_salary + overtime_amount
        else:
            total_salary = self.emp_salary
        
        print(f"Total salary of the employee {self.name} is {total_salary}")
        
    def emp_assign_department(self):
        edit_department = input("Enter the employee id to change the department: ")

        if edit_department == self.emp_department:
            new_department = input("Enter new department: ")
            self.emp_department = new_department
            print(f"Department updated successfully for {self.emp_name}")
        else:
            print("Invalid employee id")
    
    def print_employee_details(self):
        employee_details = input("Enter the employee id to view the details of the employee: ")

        if employee_details == self.emp_id:
            print(f"{self.emp_id}, {self.emp_name}, {self.emp_salary}, {self.emp_department}")
        else:
            print("Employee not found")

employees = [   
Employee("E7876", "ADAMS", 50000, "ACCOUNTING"),
Employee("E7499","JONES", 45000, "RESEARCH"),
Employee("E7900", "MARTIN", 50000, "SALES"),
Employee("E7698", "SMITH", 55000, "OPERATIONS")
]

while True:
    print("\n1.Choose an option: ")
    print("1. Change Department")
    print("2.Show employee Details")
    print("3.Calculate overtime salary")
    print("4. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        for emp in employees:
            if emp.emp_id == emp_id:
                emp.emp_assign_department()
                break
            else:
                print("Employee id not found")
    
    elif choice == "2":
        emp_id = input("Enter employee id to view the details of the employee: ")
        for emp in employees:
            if emp.emp_id == emp_id:
                emp.print_employee_details()
                break
    
    elif choice == "3":
        emp_id = input("Enter employee id to calculate the overtime salary: ")
        for emp in employees:
            if emp.emp_id == emp_id:
                emp.calculate_emp_salary()
                break
    
    elif choice == "4":
        print("Exit")

    else:
        print("Invalid choice")
