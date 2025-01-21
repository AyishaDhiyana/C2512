#include "patient_management.h"
#include "ui_common.h"

void PatientManagement::Read(std::string& name,
                              std::string& age,
                              std::string& gender,
                              std::string& email,
                              std::string& phone,
                              std::string& address,
                              std::string& location,
                              std::string& password,
                              int flags) {
    if ((flags & 1) != 0) {
        name = uiCommon.in.Str("Enter name:");
    }
    if ((flags & 2) != 0) {
        age = uiCommon.in.Str("Enter age:");
    }
    if ((flags & 4) != 0) {
        gender = uiCommon.in.Str("Enter gender:");
    }
    if ((flags & 8) != 0) {
        do {
            email = uiCommon.in.Str("Enter email:");
            if (!uiCommon.in.exist()) {
                break;
            }
            std::cout << "Email already exists. Try again.\n";
        } while (true);
    }
    if ((flags & 16) != 0) {
        phone = uiCommon.in.Str("Enter phone:");
    }
    if ((flags & 32) != 0) {
        address = uiCommon.in.Str("Enter address:");
    }
    if ((flags & 64) != 0) {
        location = uiCommon.in.Str("Enter location:");
    }
    if ((flags & 128) != 0) {
        password = uiCommon.in.Str("Enter password:");
    }
}

void PatientManagement::Create() {
    uiCommon.TitleBar("Patient Registration > Create Patient");
    std::string name, age, gender, email, phone, address, location, password;
    int flags = 31;

    Read(name, age, gender, email, phone, address, location, password, flags);

    std::cout << "Patient registered successfully.\n";
    uiCommon.PressAnyKey(true);
}

void PatientManagement::Edit() {
    uiCommon.TitleBar("Patient Management > Edit Patient");
    std::cout << "Editing patient details...\n";
    uiCommon.PressAnyKey(true);
}

void PatientManagement::Display() {
    uiCommon.TitleBar("Patient Management > List of Patients");
    std::cout << "Displaying patient details...\n";
    uiCommon.PressAnyKey(true);
}