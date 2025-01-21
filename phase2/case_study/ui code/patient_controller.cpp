#include "patient_controller.h"

void PatientController::Create() {
    uiCommon.TitleBar("Patient Management > Create Patient");
    std::cout << "Creating a new patient...\n";
    uiCommon.PressAnyKey(true);
}

void PatientController::Edit() {
    uiCommon.TitleBar("Patient Management > Edit Patient");
    std::cout << "Editing patient details...\n";
    uiCommon.PressAnyKey(true);
}

void PatientController::Display() {
    uiCommon.TitleBar("Patient Management > List of Patients");
    std::cout << "Displaying patient details...\n";
    uiCommon.PressAnyKey(true);
}