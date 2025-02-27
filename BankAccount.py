# Write a Python class BankAccount with attributes like account_number, balance, date_of_opening
#  and customer_name, and methods like deposit, withdraw, and check_balance.

class BnakAccount:

    def __init__(account,account_number, balance, date_of_opening, customer_name):
        account.account_number = account_number
        account.balance = balance
        account.date_of_opening = date_of_opening
        account.account_holder_name = account_holder_name

    def deposit(account, amount):
        amount = int(input("Enter amount: "))
        if amount > 0:
            balance += amount
            print(f"{account.account_number} Credited for Rs.{amount} and available balance is {account.balance}")
        else:
            print("Enter valid deposit amount")

    def withdraw(account, amount):
        amount = int(input("Enter withdraw amount: "))
        if amount > 0:
            if amount <= account.balance:
                account.balance -= amount
                print(f"{account.account_number} Debited for {amount} and available balance is {account.balance}")
            else:
                print("Insufficient balance")
        else:
            print("Enter valid withdrwal amount")

    def check_balace(account):
        print(f"Available balance is {account.balance}")
    
accounts = []
total_accounts = int(input("Enter number of accounts: "))

for count in range(total_accounts):
    account_number = input("Enter account number: ")
    account_balance = input("Enter the account balance: ")
    date_of_opening = input("Enter the date of opening(format: DD-MM-YYYY)")
    account_holder_name = input("Enter the account_holder_name")

    accounts.append(BnakAccount(account_number, account_balance, date_of_opening, account_holder_name))

while True:
    print("\n Choose an Option: ")
    print("1. Make a Deposit")
    print("2. Withdraw money")
    print("3. Check balance")
    print("4.Exit")

    choice = input("Enter your choice: ")

    if choice in ["1", "2", "3"]:
        account_number = input("Enter account number to see the details: ")
        account_number = False

        for acc in accounts:
            if acc.account_number == account_number:
                account_number = True
                if choice == "1":
                    acc.deposit()
                elif choice == "2":
                    acc.withdraw()
                elif choice == "3":
                    acc.check_balance()
                break
        if not account_number:
            print("Account number not found")
    elif choice == "4":
        print("Exit")

            


                

       
