==============================================================================
                                  TASK 2.1
==============================================================================

Change the crud ops with HospitalStay from array of HospitalStay called `stays`
to vector<HospitalStay> stays.

---------------------------------SOLUTION-------------------------------------

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class VaccinationManager {
private:
    vector<string> vaccinationIDs;
    vector<int> doses;

public:
    int findIndexById(string& vaccinationID);
    void create();
    void displayAll();
    void editById();
    void deleteById();
};

void printMenu();

int main() {
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
            manager.displayAll();
            break;
        case 3:
            manager.editById();
            break;
        case 4:
            manager.deleteById();
            break;
        case 5:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}

void VaccinationManager::create() {
    string vaccinationID;
    int dose;

    cout << "Enter Vaccination ID: ";
    cin >> vaccinationID;

    if (findIndexById(vaccinationID) != -1) {
        cout << "Error: Vaccination ID already exists. Please use a unique ID.\n";
        return;
    }

    cout << "Enter Number of Doses Administered: ";
    cin >> dose;

    vaccinationIDs.push_back(vaccinationID);
    doses.push_back(dose);

    cout << "Vaccination created successfully.\n";
}

void VaccinationManager::displayAll() {
    if (vaccinationIDs.empty()) {
        cout << "No vaccination available to display.\n";
        return;
    }

    cout << "--------------------------------------\n";
    cout << "|   VACCINATION ID   | DOSES ADMINISTERED |\n";
    cout << "--------------------------------------\n";

    for (size_t i = 0; i < vaccinationIDs.size(); ++i) {
        cout << "| " << setw(17) << vaccinationIDs[i] << " | "
             << setw(17) << doses[i] << " |\n";
    }
    cout << "--------------------------------------\n";
}

int VaccinationManager::findIndexById(string& vaccinationID) {
    auto iter = find(vaccinationIDs.begin(), vaccinationIDs.end(), vaccinationID);
    if (iter != vaccinationIDs.end()) {
        return distance(vaccinationIDs.begin(), iter);
    }
    return -1;
}

void VaccinationManager::editById() {
    string vaccinationID;
    cout << "Enter Vaccination ID to edit: ";
    cin >> vaccinationID;

    int index = findIndexById(vaccinationID);
    if (index == -1) {
        cout << "Error: Vaccination ID not found.\n";
        return;
    }

    cout << "Current Doses Administered: " << doses[index] << "\n";
    cout << "Enter New Number of Doses Administered: ";
    cin >> doses[index];

    cout << "Vaccination updated successfully.\n";
}

void VaccinationManager::deleteById() {
    string vaccinationID;
    cout << "Enter Vaccination ID to delete: ";
    cin >> vaccinationID;

    int index = findIndexById(vaccinationID);
    if (index == -1) {
        cout << "Error: Vaccination ID not found.\n";
        return;
    }

    vaccinationIDs.erase(vaccinationIDs.begin() + index);
    doses.erase(doses.begin() + index);

    cout << "Vaccination deleted successfully.\n";
}

void printMenu() {
    cout << "\n=== Vaccination Management System ===\n";
    cout << "1. Create Vaccination\n";
    cout << "2. Display All Vaccination\n";
    cout << "3. Edit Vaccination\n";
    cout << "4. Delete Vaccination\n";
    cout << "5. Exit\n";
}

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
