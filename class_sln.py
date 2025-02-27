class Employee:
    def __init__(self, emp_id, emp_name, emp_salary, emp_department):
        self.emp_id = emp_id
        self.emp_name = emp_name
        self.emp_salary = emp_salary
        self.emp_department = emp_department

    def calculate_emp_salary(self, hours_worked):
        if hours_worked > 50:
            overtime = hours_worked - 50
            overtime_amount = overtime * (self.emp_salary / 50)
            total_salary = self.emp_salary + overtime_amount
        else:
            total_salary = self.emp_salary

        print(f"Total salary of {self.emp_name} (ID: {self.emp_id}) is {total_salary:.2f}")

    def emp_assign_department(self, new_department):
        self.emp_department = new_department
        print(f"Department updated successfully for {self.emp_name} to {self.emp_department}")

    def print_employee_details(self):
        print(f"ID: {self.emp_id}, Name: {self.emp_name}, Salary: {self.emp_salary}, Department: {self.emp_department}")


# Creating Employee instances
employees = [
    Employee("E7876", "ADAMS", 50000, "ACCOUNTING"),
    Employee("E7499", "JONES", 45000, "RESEARCH"),
    Employee("E7900", "MARTIN", 50000, "SALES"),
    Employee("E7698", "SMITH", 55000, "OPERATIONS"),
]

while True:
    print("\nMenu:")
    print("1. Change Department")
    print("2. Show Employee Details")
    print("3. Calculate Overtime Salary")
    print("4. Exit")

    choice = input("Enter your choice: ")

    if choice in ["1", "2", "3"]:  # Common input for employee ID
        emp_id = input("Enter employee ID: ")
        employee = next((emp for emp in employees if emp.emp_id == emp_id), None)

        if not employee:
            print("Employee ID not found.")
            continue  # Go back to menu

    if choice == "1":
        new_department = input("Enter new department: ")
        employee.emp_assign_department(new_department)

    elif choice == "2":
        employee.print_employee_details()

    elif choice == "3":
        hours_worked = int(input("Enter hours worked: "))
        employee.calculate_emp_salary(hours_worked)

    elif choice == "4":
        print("Exiting...")
        break  # Exit the loop

    else:
        print("Invalid choice. Please try again.")