==============================================================================
                                  TASK 2.1
==============================================================================

Change the crud ops with HospitalStay from array of HospitalStay called `stays`
to vector<HospitalStay> stays.

---------------------------------SOLUTION-------------------------------------

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const int MAX_DOSES = 100;

class Vaccination 
{
public:
    string VaccinationID;
    int DosesAdministered;
};

class VaccinationManager 
{
private:
    vector<Vaccination> vaccinations; // Using vector instead of array.

public:
    int findIndexById(const string& VaccinationID);

    // CRUD operations
    void create();
    void display();
    void updateByID();
    void deleteByID();

    // Constructor
    VaccinationManager();
};

void printMenu();

void VaccinationTest() 
{
    VaccinationManager manager;

    int choice;

    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.create();
            break;
        case 2:
            manager.display();
            break;
        case 3:
            manager.updateByID();
            break;
        case 4:
            manager.deleteByID();
            break;
        case 5:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);
}

int main()
{
    VaccinationTest();
    
    return EXIT_SUCCESS;
}

void printMenu()
{
    cout << "\n=== Doses Administered Vaccination Management System ===\n";
    cout << "1. Create Vaccination\n";
    cout << "2. Display All Vaccination\n";
    cout << "3. Edit Vaccination\n";
    cout << "4. Delete Vaccination\n";
    cout << "5. Exit\n";
}

int VaccinationManager::findIndexById(const string& VaccinationID)
{
    for (size_t i = 0; i < vaccinations.size(); ++i) {
        if (vaccinations[i].VaccinationID == VaccinationID) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void VaccinationManager::create() 
{
    Vaccination vaccination;

    cout << "Enter Vaccination ID: ";
    cin >> vaccination.VaccinationID;

    if (findIndexById(vaccination.VaccinationID) != -1) {
        cout << "Error: Vaccination ID already exists. Please use a unique ID.\n";
        return;
    }

    cout << "Enter Number of Doses Administered: ";
    cin >> vaccination.DosesAdministered;

    vaccinations.push_back(vaccination);
    cout << "Vaccination created successfully.\n";
}

void VaccinationManager::display() 
{
    if (vaccinations.empty()) {
        cout << "No vaccination available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "| Vaccination ID | Doses Administered |\n";
    cout << "------------------------------------------------\n";
    for (const auto& vaccination : vaccinations) {
        cout << "| " << setw(15) << vaccination.VaccinationID << " | "
             << setw(16) << vaccination.DosesAdministered << " |\n";
    }
    cout << "------------------------------------------------\n";
}

void VaccinationManager::updateByID() 
{
    string VaccinationID;
    cout << "Enter Vaccination ID to edit: ";
    cin >> VaccinationID;

    int index = findIndexById(VaccinationID);
    if (index == -1) {
        cout << "Error: Vaccination ID not found.\n";
        return;
    }

    cout << "Current Doses Administered: " << vaccinations[index].DosesAdministered << "\n";
    cout << "Enter New Doses Administered: ";
    cin >> vaccinations[index].DosesAdministered;

    cout << "Vaccination updated successfully.\n";
}

void VaccinationManager::deleteByID() 
{
    string VaccinationID;
    cout << "Enter Vaccination ID to delete: ";
    cin >> VaccinationID;

    int index = findIndexById(VaccinationID);
    if (index == -1) {
        cout << "Error: Vaccination ID not found.\n";
        return;
    }

    vaccinations.erase(vaccinations.begin() + index);
    cout << "Vaccination deleted successfully.\n";
}

VaccinationManager::VaccinationManager() = default;

=======================OUTPUT===========================

  === Doses Administered Vaccination Management System ===
1. Create Vaccination
2. Display All Vaccination
3. Edit Vaccination
4. Delete Vaccination
5. Exit
Enter your choice: 1
Enter Vaccination ID: 201
Enter Number of Doses Administered: 3
Vaccination created successfully.

=== Doses Administered Vaccination Management System ===
1. Create Vaccination
2. Display All Vaccination
3. Edit Vaccination
4. Delete Vaccination
5. Exit
Enter your choice: 2
------------------------------------------------
| Vaccination ID | Doses Administered |
------------------------------------------------
|             201 |                3 |
------------------------------------------------

=== Doses Administered Vaccination Management System ===
1. Create Vaccination
2. Display All Vaccination
3. Edit Vaccination
4. Delete Vaccination
5. Exit
Enter your choice: 1
Enter Vaccination ID: 203
Enter Number of Doses Administered: 4
Vaccination created successfully.

=== Doses Administered Vaccination Management System ===
1. Create Vaccination
2. Display All Vaccination
3. Edit Vaccination
4. Delete Vaccination
5. Exit
Enter your choice: 2
------------------------------------------------
| Vaccination ID | Doses Administered |
------------------------------------------------
|             201 |                3 |
|             203 |                4 |
------------------------------------------------

=== Doses Administered Vaccination Management System ===
1. Create Vaccination
2. Display All Vaccination
3. Edit Vaccination
4. Delete Vaccination
5. Exit
Enter your choice: 3
Enter Vaccination ID to edit: 201
Current Doses Administered: 3
Enter New Doses Administered: 6
Vaccination updated successfully.

=== Doses Administered Vaccination Management System ===
1. Create Vaccination
2. Display All Vaccination
3. Edit Vaccination
4. Delete Vaccination
5. Exit
Enter your choice: 2
------------------------------------------------
| Vaccination ID | Doses Administered |
------------------------------------------------
|             201 |                6 |
|             203 |                4 |
------------------------------------------------

=== Doses Administered Vaccination Management System ===
1. Create Vaccination
2. Display All Vaccination
3. Edit Vaccination
4. Delete Vaccination
5. Exit
Enter your choice: 5
Exiting the system. Goodbye!
