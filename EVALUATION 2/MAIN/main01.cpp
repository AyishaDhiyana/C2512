#003
Implement a `Vaccination` Class with Comparison Methods in C++

`Task:` 
    Create a class `Vaccination` 
    that represents a vaccination record 
    with properties `VaccinationID` (string) and 
                    `DosesAdministered` (int). 

class Vaccination
{
    private:
        string VaccinationID;
        int DosesAdministered;
    public:
        bool Equals(const Vaccination& other);
        bool NotEquals(const Vaccination& other);
        bool GreaterThan(const Vaccination& other);
        bool GreaterThanEquals(const Vaccination& other);
        bool LessThan(const Vaccination& other);
        bool LessThanEquals(const Vaccination& other);

        Vaccination(string p_VaccinationID, int p_DosesAdministered);
};
---------------------------------------------------------------------------------------------------------
    Implement the following methods 
        to compare the number of doses administered between two vaccination records:
---------------------------------------------------------------------------------------------------------

1. `Equals(const Vaccination& other)` - 
    Checks if two vaccinations have the same number of doses administered.

bool Vaccination::Equals(const Vaccination& other)
{
        return (DosesAdministered = other.DosesAdministered);
}
----------------------------------------------------------------------------------------------------------

2. `NotEquals(const Vaccination& other)` - 
    Checks if two vaccinations have a different number of doses administered.

bool Vaccination::NotEquals(const Vaccination& other0
{
        return (DosesAdministered != other.DosesAdministered);
}
--------------------------------------------------------------------------------------------------------
3. `GreaterThan(const Vaccination& other)` - 
    Checks if one vaccination has more doses administered than another.

bool Vaccination::GreaterThan(const Vaccination& other)
{
        return (DosesAdministered > other.DosesAdministered);
}
-------------------------------------------------------------------------------------------------------

4. `GreaterThanEquals(const Vaccination& other)` - 
    Checks if one vaccination has more or the same number of doses administered as another.

bool Vaccination::GreaterThanEquals(const Vaccination& other)
{
        return (DosesAdministered >= other.DosesAdministered);
}
------------------------------------------------------------------------------------------------------

5. `LessThan(const Vaccination& other)` - 
    Checks if one vaccination has fewer doses administered than another.

bool Vaccination::LessThan(const Vaccination& other)
{
        return (DosesAdministered < other.DosesAdministered);
}

6. `LessThanEquals(const Vaccination& other)` - 
    Checks if one vaccination has fewer or the same number of doses administered as another.

bool Vaccination::LessThanEquals(const Vaccination& other)
{
        return (DosesAdministered <= other.DosesAdministered);
}
------------------------------------------------------------------------------------------------------

Vaccination::Vaccination(string p_VaccinationID, int p_DosesAdministered)
{
        VaccinationID = p_DosesAdministered;
        DosesAdministered = p_DosesAdministered;
}
--------------------------------------------------------------------------------------------------------

ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ touch main.cpp
ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ touch DosesAdministered.h
ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ touch DosesAdministered.cpp
ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ ls
DosesAdministered.cpp  DosesAdministered.h  main.cpp
ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ vim *.cpp *.h
3 files to edit
ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ cat DosesAdministered.h
#pragma once

#include <string>

using std::string;

class Vaccination
{
    private:
        string VaccinationID;
        int DosesAdministered;
    public:
        bool Equals(const Vaccination& other);
        bool NotEquals(const Vaccination& other);
        bool GreaterThan(const Vaccination& other);
        bool GreaterThanEquals(const Vaccination& other);
        bool LessThan(const Vaccination& other);
        bool LessThanEquals(const Vaccination& other);
       
        Vaccination(string p_VaccinationID, int p_DosesAdministered);
};
ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ cat DosesAdministered.cpp
#include<string>

#include "DosesAdministered.h"

using std::string;

bool Vaccination::Equals(const Vaccination& other)
{
        return (DosesAdministered == other.DosesAdministered);
}

bool Vaccination::NotEquals(const Vaccination& other)
{
        return (DosesAdministered != other.DosesAdministered);
}

bool Vaccination::GreaterThan(const Vaccination& other)
{
        return (DosesAdministered > other.DosesAdministered);
}

bool Vaccination::GreaterThanEquals(const Vaccination& other)
{
        return (DosesAdministered >= other.DosesAdministered);
}

bool Vaccination::LessThan(const Vaccination& other)
{
        return (DosesAdministered < other.DosesAdministered);
}

bool Vaccination::LessThanEquals(const Vaccination& other)
{
        return (DosesAdministered <= other.DosesAdministered);
}

Vaccination::Vaccination(string p_VaccinationID, int p_DosesAdministered)
{
        VaccinationID = p_DosesAdministered;
        DosesAdministered = p_DosesAdministered;
}
ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ cat main.cpp
#include <iostream>
#include <iomanip>

#include "DosesAdministered.h"
int main() {
    Vaccination v1("V001", 10);
    Vaccination v2("V002", 12);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << v1.Equals(v2) << std::endl; 
    std::cout << "Not Equals: " << v1.NotEquals(v2) << std::endl;
    std::cout << "GreaterThan: " << v1.GreaterThan(v2) << std::endl; 
    std::cout << "GreaterThanEquals: " << v1.GreaterThanEquals(v2) << std::endl; 
    std::cout << "LessThan: " << v1.LessThan(v2) << std::endl;
    std::cout << "LessThanEquals: " << v1.LessThanEquals(v2) << std::endl; 

    return 0;
}
ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ g++ -c *.cpp
ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ g++ -o App.out *.o
ayisha@DESKTOP-0EIRMV5:/mnt/c/Users/DELL/Cpp$ ./App.out
Equals: false
Not Equals: true
GreaterThan: false
GreaterThanEquals: false
LessThan: true
LessThanEquals: true
