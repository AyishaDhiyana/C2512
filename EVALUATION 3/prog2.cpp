=============================================================
       single inheritance using static binding:
=============================================================
Create two static objects for Both Base and Derived class
and call all behaviours
and 
one two dynamic objects for Base and Derived class 
and call all behaviours

Define constructors and destructors for all the classes 

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
    ~Vehicle()
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
    Vehicle vehicle(150);
    Car car(100,"Petrol");
    
    vehicle.start();
    car.start();
    car.drive();
    
    return EXIT_SUCCESS;
}
