##include "ui_common.h"
#include "admin_main.h"

void ManagePatient() {
    PatientController controller;

    uiCommon.TitleBar("Patient Management System");
    std::cout << "1. Create Patient\n";
    std::cout << "2. Edit Patient\n";
    std::cout << "3. Display Patients\n";
    std::cout << "4. Exit\n";

    int choice = uiCommon.in.Int("Enter your choice:");
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
            std::cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
    }
}