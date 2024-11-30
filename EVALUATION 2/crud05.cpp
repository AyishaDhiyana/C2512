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
