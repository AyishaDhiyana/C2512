#include "frontdesk.h"
#include <iostream>
#include <vector>
#include <regex>

// Declaring the patients vector to store patient records
std::vector<Patient> patients;

// Front Desk Menu Function
void frontDeskMenu() {
    int choice;
    std::cout << "1. Register Patient\n";
    std::cout << "2. Edit Patient Information\n";
    std::cout << "3. View Patient Details\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            registerPatient();
            break;
        case 2:
            editPatient();
            break;
        case 3: {
            std::string query;
            std::cout << "Enter Patient ID or Name or Phone: ";
            std::cin >> query;
            viewPatient(query);
            break;
        }
        case 4:
            std::cout << "Exiting Front Desk...\n";
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}

// Function to Register a New Patient
void registerPatient() {
    Patient newPatient;

    std::cout << "Enter Patient ID: ";
    std::cin >> newPatient.patientId;

    std::cout << "Enter Name: ";
    std::cin.ignore(); // To clear the input buffer before reading a string
    std::getline(std::cin, newPatient.name);

    std::cout << "Enter Age: ";
    std::cin >> newPatient.age;

    std::cout << "Enter Gender (M/F): ";
    std::cin >> newPatient.gender;

    std::cout << "Enter Email: ";
    std::cin >> newPatient.email;

    std::cout << "Enter Phone: ";
    std::cin >> newPatient.phone;

    std::cout << "Enter Address: ";
    std::cin.ignore(); // To clear the input buffer before reading a string
    std::getline(std::cin, newPatient.address);

    std::cout << "Enter Location: ";
    std::getline(std::cin, newPatient.location);

    if (isValidEmail(newPatient.email) && isValidPhone(newPatient.phone) && !isDuplicatePatient(newPatient.email, newPatient.phone)) {
        patients.push_back(newPatient);
        std::cout << "Patient registered successfully.\n";
    } else {
        std::cout << "Registration failed. Invalid details or duplicate patient.\n";
    }
}

// Function to Edit Patient Information
void editPatient() {
    std::string patientId;
    std::cout << "Enter Patient ID to edit: ";
    std::cin >> patientId;

    for (auto& patient : patients) {
        if (patient.patientId == patientId) {
            std::cout << "Enter new Location: ";
            std::cin.ignore(); // To clear the input buffer before reading a string
            std::getline(std::cin, patient.location);
            std::cout << "Patient location updated successfully.\n";
            return;
        }
    }
    std::cout << "Patient not found.\n";
}

// Function to View Patient Details (Search by ID, Name or Phone)
void viewPatient(const std::string& query) {
    for (const auto& patient : patients) {
        if (patient.patientId == query || patient.name == query || patient.phone == query) {
            displayPatient(patient);
            return;
        }
    }
    std::cout << "Patient not found.\n";
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

// Function to Validate Email (Simple Regex)
bool isValidEmail(const std::string& email) {
    std::regex emailPattern(R"((\w+)(\.{0,1})(\w*)@(\w+)(\.[a-z]{2,3})+)");
    return std::regex_match(email, emailPattern);
}

// Function to Validate Phone Number (Only Numbers, Length 10)
bool isValidPhone(const std::string& phone) {
    std::regex phonePattern(R"(\d{10})");
    return std::regex_match(phone, phonePattern);
}

// Function to Check for Duplicate Patients (Based on Email or Phone)
bool isDuplicatePatient(const std::string& email, const std::string& phone) {
    for (const auto& patient : patients) {
        if (patient.email == email || patient.phone == phone) {
            return true;
        }
    }
    return false;
}