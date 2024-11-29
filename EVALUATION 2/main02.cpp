#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::boolalpha;


class Vaccination
{
	private:
		string VaccinationID;
		int DosesAdministered;
	public:
	//constructor
		Vaccination (string p_VaccinationID, int p_DosesAdministered);

		friend bool Equals(const Vaccination& first, const Vaccination& second);
		friend bool LessThan(const Vaccination& first, const Vaccination& second);
		friend bool LessThanEquals(const Vaccination& first, const Vaccination& second);
		friend bool GreaterThan(const Vaccination& first, const Vaccination& second);
		friend bool GreaterThanEquals(const Vaccination& first, const Vaccination& second);
};

bool Equals (const Vaccination& first, const Vaccination& second);
bool LessThan (const Vaccination& first, const Vaccination& second);
bool LessThanEquals (const Vaccination& first, const Vaccination& second);
bool GreaterThan (const Vaccination& first, const Vaccination& second);
bool GreaterThanEquals (const Vaccination& first, const Vaccination& second);

int main()
{
	Vaccination v1 ("V001", 5);
	Vaccination v2 ("V002", 7);

	cout << std::boolalpha;
	cout << "Equals: " << Equals(v1, v2) << endl;
	cout << "LessThan: " << LessThan(v1, v2) << endl;
	cout << "LessThanEquals: " << LessThanEquals(v1, v2) << endl;
	cout << "GreaterThan: " << GreaterThan(v1, v2) << endl;
	cout << "GreaterThanEquals: " << GreaterThanEquals(v1, v2) << endl;;
	
	return EXIT_SUCCESS;
}

bool Equals(const Vaccination& first, const Vaccination& second)
{
	return (first.DosesAdministered == second.DosesAdministered);
}
bool LessThan(const Vaccination& first, const Vaccination& second)
{
        return (first.DosesAdministered < second.DosesAdministered);
}
bool LessThanEquals(const Vaccination& first, const Vaccination& second)
{
        return (first.DosesAdministered <= second.DosesAdministered);
}
bool GreaterThan(const Vaccination& first, const Vaccination& second)
{
        return (first.DosesAdministered > second.DosesAdministered);
}
bool GreaterThanEquals(const Vaccination& first, const Vaccination& second)
{
        return (first.DosesAdministered >= second.DosesAdministered);
}

Vaccination::Vaccination (string p_VaccinationID, int p_DosesAdministered)
{
        VaccinationID = p_VaccinationID;
        DosesAdministered = p_DosesAdministered;
}
