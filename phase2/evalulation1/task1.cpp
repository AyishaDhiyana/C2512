#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;
class Vaccination
{
	private:
	std::string VaccinationId;
	int DosesAdministered;
	
	public:
	Vaccination(std::string p_VaccinationId, int p_DosesAdministered) : VaccinationId(p_VaccinationId), DosesAdministered(p_DosesAdministered) {}
    int getDoses() { return DosesAdministered;}
    
};
int findSum(std::vector<Vaccination>& doses)
{
    int sum = 0;
	for(int i = 0; i < doses.size(); i++)
    {
        sum = sum + doses[i].getDoses();
    }
    return sum;
}

int firstMinInHalf(std::vector<Vaccination>& doses)
{
    int min = INT_MAX;
    for(size_t i = 0; i < doses.size()/2; i++)
    {
    if(doses[i].getDoses() < min)
    {
        min = doses[i].getDoses();
    }
    }
    return min;
}	

int secondHalfMax(std::vector<Vaccination>& doses)
{  
	int max = INT_MIN;
    for(size_t i = ((doses.size())/2); i < doses.size(); i++)
    if(doses[i].getDoses() > max)
    {
        max = doses[i].getDoses(); 
    }
    return max;
}

int main()
{
	std::vector<Vaccination> doses;
    doses.emplace_back("V001", 3);
    doses.emplace_back("V002", 4);
    doses.emplace_back("V003", 5);
    doses.emplace_back("V004", 6);
    doses.emplace_back("V005", 10);

    int sum = findSum(doses);
    cout << "sum is " << sum << std::endl;

    int min = firstMinInHalf(doses);
    cout << "minimum value is " << min << std::endl;

    int max = secondHalfMax(doses);
    cout << "maximum value in the second half is " << max << std::endl;

	return 0;
}
