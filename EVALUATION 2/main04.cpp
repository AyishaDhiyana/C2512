#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;

class Vaccination
{
    private:
        string VaccinationID;
        int DosesAdministered;
    public:
        //constructor
        Vaccination (string p_VaccinationID, int p_DosesAdministered);
        friend class Comparisions; 
};

class Comparisions
{
    public:
        static bool LessThan (const Vaccination& first, const Vaccination& second);
        static bool GreaterThan (const Vaccination& first, const Vaccination& second);
};

int main ()
{
    Vaccination v1 ("V001", 5);
    Vaccination v2 ("V002", 7);
    
    cout << std::boolalpha;
    cout << "LessThan: " << Comparisions::LessThan (v1, v2) << endl;;
    cout << "GreaterThan: " << Comparisions::GreaterThan (v1, v2) << endl;

    return EXIT_SUCCESS;
}

bool Comparisions::LessThan(const Vaccination& first, const Vaccination& second)
{
    return (first.DosesAdministered < second.DosesAdministered);
}

bool Comparisions::GreaterThan(const Vaccination& first, const Vaccination& second)
{
    return (first.DosesAdministered > second.DosesAdministered);
}

Vaccination::Vaccination (string p_VaccinationID, int p_DosesAdministered)
{
    VaccinationID = p_VaccinationID;
    DosesAdministered = p_DosesAdministered;
}
