#ifndef PATIENT_MANAGEMENT_H
#define PATIENT_MANAGEMENT_H

#include <string>

class PatientManagement {
public:
    static void Read(std::string& name,
                     std::string& age,
                     std::string& gender,
                     std::string& email,
                     std::string& phone,
                     std::string& address,
                     std::string& location,
                     std::string& password,
                     int flags = 129);

    void Create();
    void Edit();
    void Display();
};

#endif // PATIENT_MANAGEMENT_H