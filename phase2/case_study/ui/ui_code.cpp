#include<iostream>
#include<sstream>
#include<string>

#include"./../headers/admin_main.h"
#include"./../headers/ui_common.h"

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
            int flags = 129) {

            
            if((flags & 1) != 0) {
                name = uiCommon.in.Str("Enter name:");
            }
            if((flags & 2) != 0) {
                name = uiCommon.in.Str("Enter age:");
            }
            if((flags & 4) != 0) {
                name = uiCommon.in.Str("Enter gender:");
            }
            if((flags & 8) != 0) {
                do {
                    email = uiCommon.in.Str("Enter email:");
                    if(!uiCommon.in.exist()) {
                        break;
                    }
                    std::cout << "Email exist." << std::endl;
                } while(true);
            if((flags & 16) != 0) {
                phone = uiCommon.in.Str("Enter phone:");
            }
            }
            if((flags & 36) != 0) {
                name = uiCommon.in.Str("Enter address:");
            }
            if((flags & 64) != 0) {
                name = uiCommon.in.Str("Enter location:");
            }
            if((flags & 128) != 0) {
                password = uiCommon.in.Str("Enter password:");
            }
        }

        void Create() {
            uiCommon.TitleBar("Patient Registration > Create Patient");
            int flags = 31;
            std::string name;
            std::string age;
            std::string gender;
            std::string email;
            std::string phone;
            std::string address;
            std::string location;
            std::string password;
            
            do {
                Read(name, age, gender, email, phone, address, location, password, flags);
                int proceedOption; 

                std::stringstream soutput; 
                soutput << "1 - edit `name`." << std::endl; 
                soutput << "2 - edit `age`." << std::endl; 
                soutput << "4 - edit `gender`." << std::endl;
                soutput << "8 - edit `email`." << std::endl; 
                soutput << "16 - edit `phone`." << std::endl; 
                soutput << "32 - edit `address`." << std::endl; 
                soutput << "64 - location`." << std::endl; 
                soutput << "128 - password." << std::endl;
                soutput << "\tYour choice:"; 
                proceedOption = uiCommon.in.Int(soutput.str());

                if(91 == proceedOption) {
                    //set to biz object
                    break;
                }
                flags = proceedOption;
            } while(true);
            std::cout << "Patient is registered successfully." << std::endl;
            uiCommon.PressAnyKey(true);        
        }

        void Edit() {
            uiCommon.TitleBar(" Patient Management > Edit Admin");
            uiCommon.PressAnyKey(true); 
        }

        void Display() {
            uiCommon.TitleBar("Patient Management > List of Admins");
            uiCommon.PressAnyKey(true); 
        }
};

static int ReadPatientMenu() {
    int choice;
    
    uiCommon.TitleBar("Patient Page > Patient  Management");

    std::stringstream soutput;
    soutput << "1 - Create Patient" << std::endl;
    soutput << "2 - Edit Patient" << std::endl;
    soutput << "4 - Display Patient" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void ManagePatient() { 
    PatientController controller;
    
    int choice;

    do { 
        choice = ReadPatientMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
                controller.Display();
            } break;
        }
    } while(99 != choice);
}
