#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>

// Patient Structure (same as in frontdesk.h)
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

// Admin Functions
void adminMenu();
void viewAllPatients();
void deletePatient();
void displayPatient(const Patient& patient);
bool isPatientExist(const std::string& patientId);

extern std::vector<Patient> patients;

#endif