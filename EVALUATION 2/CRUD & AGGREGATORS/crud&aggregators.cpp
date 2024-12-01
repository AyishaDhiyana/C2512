#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAX_DOSES = 100;

class Vaccination
{
    friend class VaccinationManager;

    private:
    string VaccinationID;
    int DosesAdministered;

    public:
        bool GreaterThan(const Vaccination& other);
        bool LessThan(const Vaccination& other);
         //getters-setters
        string GetVaccinationID();
        int GetDosesAdministered(); 
};

class VaccinationManager
{
    friend class VaccinationAggregator;
    friend void VaccinationTest() ;
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

class VaccinationAggregator
{
    public:
    
        int findMin(VaccinationManager& manager);
        int findMax(VaccinationManager& manager);
        int findSecondMin(VaccinationManager& manager);
        int findSecondMax(VaccinationManager& manager);
};

void printMenu();

void VaccinationTest(void) 
{
    VaccinationManager manager;
    VaccinationAggregator aggregator;

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
                cout << "Vaccination with min DosesAdministered\n"
                     << manager.vaccination[aggregator.findMin(manager)].GetVaccinationID()
                     << " with DosesAdministered " 
                     <<manager.vaccination[aggregator.findMin(manager)].GetDosesAdministered() << endl;
                break;
                 case 6: 
                std::cout << "Vaccination with Max DosesAdministered: " 
                    << manager.vaccination[aggregator.findMax(manager)].GetVaccinationID() 
                    << " with DosesAdministered " 
                    << manager.vaccination[aggregator.findMax(manager)].GetDosesAdministered() 
                    << std::endl;
                break;
            case 7: 
                std::cout << "Vaccination with 2nd Min Stay: " 
                    << manager.vaccination[aggregator.findSecondMin(manager)].GetVaccinationID() 
                    << " with DosesAdministered " 
                    << manager.vaccination[aggregator.findSecondMin(manager)].GetDosesAdministered() 
                    << std::endl;
                break;
            case 8: 
                std::cout << "Vaccination with 2nd Max Stay: " 
                    << manager.vaccination[aggregator.findSecondMax(manager)].GetVaccinationID() 
                    << " with DosesAdministered " 
                    << manager.vaccination[aggregator.findSecondMax(manager)].GetDosesAdministered() 
                    << std::endl;
                break;
            case 9:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 9);
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
    cout << "5. Minimum DosageAdministered\n";
    cout << "6. Maximum DosageAdministered\n";
    cout << "7. 2nd Minimum DosageAdministered\n";
    cout << "8. 2nd Maximum DosageAdministered\n";
    cout << "9. Exit\n";
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

bool Vaccination::GreaterThan(const Vaccination& other)
{
    return (DosesAdministered > other.DosesAdministered);
}
bool Vaccination::LessThan(const Vaccination& other)
{
    return (DosesAdministered < other.DosesAdministered);
}

string Vaccination::GetVaccinationID()
{
    return VaccinationID;
}

int Vaccination::GetDosesAdministered()
{
    return DosesAdministered;
}

int VaccinationAggregator::findMin(VaccinationManager& manager)
{
    Vaccination* arr = manager.vaccination;
    int& n = manager.numDoses;
    //
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].LessThan(arr[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}

int VaccinationAggregator::findMax(VaccinationManager& manager)
{
    Vaccination* arr = manager.vaccination;
    int& n = manager.numDoses;
    //
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].GreaterThan(arr[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int VaccinationAggregator::findSecondMin(VaccinationManager& manager)
{
    Vaccination* arr = manager.vaccination;
    int& n = manager.numDoses;
    //
    int minIndex = findMin(manager);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;

    for (int i = 0; i < n; ++i) {
        if (i != minIndex) {
            if (arr[i].LessThan(arr[secondMinIndex])) {
                secondMinIndex = i;
            }
        }
    }
    return secondMinIndex;
}

int VaccinationAggregator::findSecondMax(VaccinationManager& manager)
{
    Vaccination* arr = manager.vaccination;
    int& n = manager.numDoses;
    //
    int maxIndex = findMin(manager);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;

    for (int i = 0; i < n; ++i) {
        if (i != maxIndex) {
            if (arr[i].LessThan(arr[secondMaxIndex])) {
                secondMaxIndex = i;
            }
        }
    }
    return secondMaxIndex;
}

VaccinationManager::VaccinationManager()
{
    numDoses = 0;
}
