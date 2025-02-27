class Employee:
    def __init__(self, emp_id, emp_name, emp_salary, emp_department):
        self.emp_id = emp_id
        self.emp_name = emp_name
        self.emp_salary = emp_salary
        self.emp_department = emp_department

    def calculate_emp_salary(self):
        """Takes user input for hours worked and calculates salary including overtime."""
        hours_worked = int(input(f"Enter the hours worked by {self.emp_name} ({self.emp_id}): "))

        if hours_worked > 50:
            overtime = hours_worked - 50
            overtime_amount = overtime * (self.emp_salary / 50)
            total_salary = self.emp_salary + overtime_amount
        else:
            total_salary = self.emp_salary
        
        print(f"Total Salary for {self.emp_name}: {total_salary}")

    def emp_assign_department(self):
        """Takes user input for employee ID and assigns a new department."""
        edit_id = input("Enter the employee ID to change the department: ")

        if edit_id == self.emp_id:
            new_department = input(f"Enter new department for {self.emp_name}: ")
            self.emp_department = new_department
            print(f"Department updated successfully for {self.emp_name}!")
        else:
            print("Invalid Employee ID!")

    def print_employee_details(self):
        """Takes user input for employee ID and prints details if matched."""
        employee_details = input("Enter the employee ID to view details: ")

        if employee_details == self.emp_id:
            print(f"Employee ID: {self.emp_id}")
            print(f"Name: {self.emp_name}")
            print(f"Salary: {self.emp_salary}")
            print(f"Department: {self.emp_department}")
        else:
            print("Employee not found!")

# Creating Employee Objects
employees = [
    Employee("E7876", "ADAMS", 50000, "ACCOUNTING"),
    Employee("E7499", "JONES", 45000, "RESEARCH"),
    Employee("E7900", "MARTIN", 50000, "SALES"),
    Employee("E7698", "SMITH", 55000, "OPERATIONS")
]

# User Input for Actions
while True:
    print("\nChoose an option:")
    print("1. Change Department")
    print("2. Show Employee Details")
    print("3. Calculate Salary with Overtime")
    print("4. Exit")
    
    choice = input("Enter your choice: ")

    if choice == "1":
        emp_id = input("Enter Employee ID to change department: ")
        for emp in employees:
            if emp.emp_id == emp_id:
                emp.emp_assign_department()
                break
        else:
            print("Employee ID not found!")

    elif choice == "2":
        emp_id = input("Enter Employee ID to view details: ")
        for emp in employees:
            if emp.emp_id == emp_id:
                emp.print_employee_details()
                break
        else:
            print("Employee ID not found!")

    elif choice == "3":
        emp_id = input("Enter Employee ID to calculate salary: ")
        for emp in employees:
            if emp.emp_id == emp_id:
                emp.calculate_emp_salary()
                break
        else:
            print("Employee ID not found!")

    elif choice == "4":
        print("Exiting program...")
        break

    else:
        print("Invalid choice! Please enter a valid option.")
