#include "admin.h"
#include <iostream>
#include <vector>

// Declaring the patients vector (same as in frontdesk.cpp)
std::vector<Patient> patients;

// Admin Menu Function
void adminMenu() {
    int choice;
    std::cout << "1. View All Patients\n";
    std::cout << "2. Delete Patient Record\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            viewAllPatients();
            break;
        case 2:
            deletePatient();
            break;
        case 3:
            std::cout << "Exiting Admin Portal...\n";
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}

// Function to View All Patients
void viewAllPatients() {
    if (patients.empty()) {
        std::cout << "No patients registered yet.\n";
    } else {
        for (const auto& patient : patients) {
            displayPatient(patient);
            std::cout << "---------------------------------\n";
        }
    }
}

// Function to Delete Patient Record
void deletePatient() {
    std::string patientId;
    std::cout << "Enter Patient ID to delete: ";
    std::cin >> patientId;

    bool found = false;
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->patientId == patientId) {
            patients.erase(it);
            std::cout << "Patient record deleted successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Patient not found.\n";
    }
}

// Function to Display Patient Information
void displayPatient(const Patient& patient) {
    std::cout << "Patient ID: " << patient.patientId << "\n";
    std::cout << "Name: " << patient.name << "\n";
    std::cout << "Age: " << patient.age << "\n";
    std::cout << "Gender: " << patient.gender << "\n";
    std::cout << "Email: " << patient.email << "\n";
    std::cout << "Phone: " << patient.phone << "\n";
    std::cout << "Address: " << patient.address << "\n";
    std::cout << "Location: " << patient.location << "\n";
}

// Function to Check if Patient Exists (By ID)
bool isPatientExist(const std::string& patientId) {
    for (const auto& patient : patients) {
        if (patient.patientId == patientId) {
            return true;
        }
    }
    return false;
}