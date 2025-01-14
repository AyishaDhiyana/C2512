#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <climits>

using namespace std;
class Vaccination
{
	private:
	std::string VaccinationId;
	int DosesAdministered;
	
	public:
	Vaccination(std::string p_VaccinationId, int p_DosesAdministered) : VaccinationId(p_VaccinationId), DosesAdministered(p_DosesAdministered) {}
    int getVaccinations() 
    { 
        return DosesAdministered;
    }   
};

void findSum(std::vector<Vaccination>& vaccinations, int& sum)
{
    sum = 0;
	for(int i = 0; i < vaccinations.size(); i++)
    {
        sum = sum + vaccinations[i].getVaccinations();
    }
}

void firstMinInHalf(std::vector<Vaccination>& vaccinations, int& min)
{
    min = INT_MAX;
    for(size_t i = 0; i < vaccinations.size()/2; i++)
    {
        if(vaccinations[i].getVaccinations() < min)
        {
            min = vaccinations[i].getVaccinations();
        }
    }
}	

void secondHalfMax(std::vector<Vaccination>& vaccinations, int& max)
{  
	max = INT_MIN;
    for(size_t i = ((vaccinations.size())/2); i < vaccinations.size(); i++)
    {
        if(vaccinations[i].getVaccinations() > max)
        {
            max = vaccinations[i].getVaccinations(); 
        }
    }
}

int main()
{
    std::vector<Vaccination> vaccinations;
    vaccinations.emplace_back("V001", 3);
    vaccinations.emplace_back("V002", 4);
    vaccinations.emplace_back("V003", 5);
    vaccinations.emplace_back("V004", 6);
    vaccinations.emplace_back("V005", 10);

    int sum, min, max;

    thread thr1(findSum, std::ref(vaccinations), std::ref(sum));
    thread thr2(firstMinInHalf, std::ref(vaccinations), std::ref(min));
    thread thr3(secondHalfMax, std::ref(vaccinations), std::ref(max));

    thr1.join();
    thr2.join();
    thr3.join();

    cout << "sum is " << sum << std::endl;
    cout << "minimum value is " << min << std::endl;
    cout << "maximum value in the second half is " << max << std::endl;

	return 0;
}
