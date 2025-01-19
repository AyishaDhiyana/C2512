#ifndef FRONTDESK_H
#define FRONTDESK_H

#include <string>
#include <vector>

// Patient Structure
struct Patient {
    std::string patientId;
    std::string name;
    int age;
    std::string gender;
    std::string email;
    std::string phone;
    std::string address;
    std::string location;
};

// Front Desk Functions
void frontDeskMenu();
void registerPatient();
void editPatient();
void viewPatient(const std::string& query);
void displayPatient(const Patient& patient);
bool isValidEmail(const std::string& email);
bool isValidPhone(const std::string& phone);
bool isDuplicatePatient(const std::string& email, const std::string& phone);

extern std::vector<Patient> patients;

#endif