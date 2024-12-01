#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using std::boolalpha;
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
    //friend
		friend bool LessThan(const Vaccination& first, const Vaccination& second);
		friend bool GreaterThan(const Vaccination& first, const Vaccination& second);
};

bool LessThan(const Vaccination& first, const Vaccination& second);
bool GreaterThan(const Vaccination& first, const Vaccination& second);

class Medication 
{
    private:
        string MedicationID;
        double DosagePerDay;
    public:
        //constructor
        Medication (string p_MedicationID, double p_DosagePerDay);
        //friend
        friend bool LessThan(const Medication& first, const Medication& second);
        friend bool GreaterThan(const Medication& first, const Medication& second);  
};

bool LessThan(const Medication& first, const Medication& second);
bool GreaterThan(const Medication& first, const Medication& second);  

int main()
{
    Vaccination v1("V001", 5);
    Vaccination v2("V002", 7);

    Medication m1("M001", 103.25);
    Medication m2("M002", 290.50);

    cout << std::boolalpha;
    cout << "Less Than: " << LessThan(v1, v2) << endl;
    cout << "GreaterThan: " << GreaterThan(v1, v2) << endl;
    cout << "Less Than: " << LessThan(m1, m2) << endl;
    cout << "GreaterThan: " << GreaterThan(m1, m2) << endl;

    return EXIT_SUCCESS;
}

bool LessThan(const Vaccination& first, const Vaccination& second)
{
        return (first.DosesAdministered < second.DosesAdministered);
}
bool GreaterThan(const Vaccination& first, const Vaccination& second)
{
        return (first.DosesAdministered > second.DosesAdministered);
}
bool LessThan(const Medication& first, const Medication& second)
{
        return (first.DosagePerDay < second.DosagePerDay);
}
bool GreaterThan(const Medication& first, const Medication& second)
{
        return (first.DosagePerDay > second.DosagePerDay);
}

Medication::Medication (string p_MedicationID, double p_DosagePerDay)
{
        MedicationID = p_MedicationID;
        DosagePerDay = p_DosagePerDay;
}

Vaccination::Vaccination (string p_VaccinationID, int p_DosesAdministered)
{
        VaccinationID = p_VaccinationID;
        DosesAdministered = p_DosesAdministered;
}
