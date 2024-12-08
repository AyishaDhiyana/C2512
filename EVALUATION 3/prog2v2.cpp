C++ code :
  
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
//base class
class Vehicle
{
    public: 
    //field
    int maxSpeed;
    //constructor
    Vehicle(const int maxSpeed) : maxSpeed(maxSpeed)
    {
        cout << "Vehicle constructor calls call for " << maxSpeed << endl;
    }
    //destructor
    virtual ~Vehicle()
    {
        cout << "Vehicle destructor calls for " << maxSpeed << endl;
    }
    //behaviour
    void start()
    {
        cout << "Vechile starts and reached a maxSpeed of " << maxSpeed << "km/sec " << endl;
    }
};
//Derived class
class Car : public Vehicle
{
    public:
    string fuelType;
    //constructor
    Car(const int maxSpeed, const string fuelType) : Vehicle(maxSpeed), fuelType(fuelType)
    {
        cout << "Car constructor is called for " << fuelType << endl;
    }
    //destructor
    ~Car()
    {
        cout << "Car destructor is called for " << fuelType << endl;
    }
    //behaviour
    void drive()
    {
        cout << "Car drives using " << fuelType << endl;
    }
};

int main()
{
    
    Vehicle* vehicle = new Vehicle(100);
    Car* car = new Car(100, "Pertol");
    
    vehicle->start();
    car->start();
    car->drive();
    
    delete vehicle;
    delete car;
    
    return EXIT_SUCCESS;
}

-----------------------OUTPUT---------------------------

Vehicle constructor calls call for 100
Vehicle constructor calls call for 100
Car constructor is called for Pertol
Vechile starts and reached a maxSpeed of 100km/sec 
Vechile starts and reached a maxSpeed of 100km/sec 
Car drives using Pertol
Vehicle destructor calls for 100
Car destructor is called for Pertol
Vehicle destructor calls for 100
