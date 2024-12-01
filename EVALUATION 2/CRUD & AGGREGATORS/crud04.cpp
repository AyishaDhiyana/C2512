#include <iostream>
#include <cstdlib>
#include <iomanip>

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
    //attributes
        Vaccination vaccination[MAX_DOSES];
        int numDoses;
    public:
        int findIndexById(string VaccinationID);
        //behaviours
        void create();
        void display();
        void updateByID();
        void deleteByID();
        //constructor
        VaccinationManager();
};

void printMenu();

void VaccinationTest(void) 
{
    VaccinationManager manager;

    int choice;

    do 
    {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
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

int main(void)
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

void VaccinationManager::create() 
{
    if (numDoses >= MAX_DOSES) 
    {
        cout << "Error: Maximum Doses limit reached.\n";
        return;
    }

    string VaccinationID;
    int DosesAdministered;

    cout << "Enter Vaccination ID: ";
    cin >> VaccinationID;

    if (findIndexById(VaccinationID) != -1) 
    {
        cout << "Error: Vaccination ID already exists. Please use a unique ID.\n";
        return;
    }

    cout << "Enter Number of DosesAdministered: ";
    cin >> DosesAdministered;

    vaccination[numDoses].VaccinationID = VaccinationID;
    vaccination[numDoses].DosesAdministered = DosesAdministered;
    numDoses++;

    cout << "Total bookings till date: " << numDoses << endl;
    cout << "Vaccination created successfully.\n";
}

void VaccinationManager::display() 
{
    if (numDoses == 0) 
    {
        cout << "No vaccination available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "| Vaccination ID | Doses Administered |\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < numDoses; i++) {
        cout << "| " << setw(10) << vaccination[i].VaccinationID << " | "
             << setw(12) << vaccination[i].DosesAdministered << " |\n";
    }
    cout << "------------------------------------------------\n";
}

int VaccinationManager::findIndexById(string VaccinationID) 
{
    for (int i = 0; i < numDoses; i++) 
    {
        if (vaccination[i].VaccinationID == VaccinationID) {
            return i;
        }
    }
    return -1;
}
void VaccinationManager::updateByID() 
{
    string VaccinationID;
    cout << "Enter Vaccination ID to edit: ";
    cin >> VaccinationID;

    int index = findIndexById(VaccinationID);
    if (index == -1) {
        cout << "Error: Booking ID not found.\n";
        return;
    }
    cout << "Current Details - DosesAdministered: " << vaccination[index].DosesAdministered << "\n";
    cout << "Enter New DosesAdministered: ";
    cin >> vaccination[index].DosesAdministered;
    cout << "Vaccination updated successfully.\n";
}

void VaccinationManager::deleteByID() 
{
    string VaccinationID;
    cout << "Enter Booking ID to delete: ";
    cin >> VaccinationID;

    int index = findIndexById(VaccinationID);
    if (index == -1) 
    {
        cout << "Error: Vaccination ID not found.\n";
        return;
    }

    for (int i = index; i < numDoses - 1; i++) 
    {
        vaccination[i] = vaccination[i + 1];
    }
    numDoses--;

    cout << "Vaccination deleted successfully.\n";
}

VaccinationManager::VaccinationManager()
{
    numDoses = 0;
}
