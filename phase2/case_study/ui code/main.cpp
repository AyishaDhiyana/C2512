#include <iostream>
#include "ui_common.h"
#include "patient_controller.h"

void ManagePatient() {
    PatientController controller;
    int choice;

    do {
        std::cout << "\nPatient Management Menu:\n";
        std::cout << "1. Create Patient\n";
        std::cout << "2. Edit Patient\n";
        std::cout << "3. Display Patient Details\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                controller.Create();
                break;
            case 2:
                controller.Edit();
                break;
            case 3:
                controller.Display();
                break;
            case 4:
                std::cout << "Exiting Patient Management...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

int main() {
    ManagePatient();
    return 0;
}
