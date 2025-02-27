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
    def __init__(emp, emp_id, emp_name, emp_salary, emp_department):
        emp.emp_id = emp_id
        emp.emp_name = emp_name
        emp.emp_salary = emp_salary
        emp.emp_department = emp_department

    def calculate_emp_salary(self,hours_worked):
        hours_worked = input("Enter the hours worked by the employee: ")
        if (hours_worked > 50):
            overtime = hours_worked - 50
            overtime_amount = (overtime * (emp_salary / 50))
            total_salary = self.emp_salary + overtime_amount
        else:
            total_salary = self.emp_salary
        return total_salary
        
    def emp_assign_department(self, emp_department):
        edit = input("Enter the employee id to change the department: ")
        if (edit == emp_department):
            new_department = input("Enter new department: ")
            self.emp_department = new_department
        print(new_department)
    
    def print_employee_details(self):
        employee_details = input("Enter the employee id to print the details of the employee: ")
        if (employee_details == emp_id):
            print(f"{emp_id}, {emp_name}, {emp_salary}, {emp_department}")
    
employee1 = Employee("E7876", "ADAMS", 50000, "ACCOUNTING")
employee2 = Employee("E7499","JONES", 45000, "RESEARCH")
employee3 = Employee("E7900", "MARTIN", 50000, "SALES")
employee4 = Employee("E7698", "SMITH", 55000, "OPERATIONS")
