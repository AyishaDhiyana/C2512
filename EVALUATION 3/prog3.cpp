single inheritance with dynamic binding
=============================================================
one two dynamic/static objects of the Derived class 
pointed by base class pointer
and call all behaviours using Base class pointer 

Override Base Class behaviors to derived class.
Define constructors and destructors for all the classes 
Define all the fields as dynamic fields in each class 

If you use string, use c-string (don't use string class)
        ie. dynamic c-string [dynamic char array]
==========================================================

C++ code :

#include <iostream>
#include <cstdlib>

using namespace std;

class Shape
{
public:
    // Constructor
    Shape()
    {
        cout << "Shape constructor is called" << endl;
    }

    // Destructor
    virtual ~Shape()
    {
        cout << "Shape destructor is called" << endl;
    }

    // Pure virtual behaviors
    virtual void calculateArea() = 0;
    virtual void calculatePerimeter() = 0;
};

class Rectangle : public Shape
{
public:
    // Attributes
    int length;
    int breadth;

    // Constructor
    Rectangle(const int length, const int breadth) : length(length), breadth(breadth)
    {
        cout << "Rectangle constructor is called" << endl;
    }

    // Destructor
    ~Rectangle()
    {
        cout << "Rectangle destructor is called" << endl;
    }

    // Behaviors
    void calculateArea() override
    {
        float area = length * breadth;
        cout << "Area is " << area << endl;
    }

    void calculatePerimeter() override
    {
        float perimeter = 2 * (length + breadth);
        cout << "Perimeter is " << perimeter << endl;
    }
};

int main()
{
    Shape* rectangle = new Rectangle(3, 5);
    rectangle->calculateArea();
    rectangle->calculatePerimeter();

    delete rectangle;

    return EXIT_SUCCESS;
}

=============OUTPUT=====================

Shape constructor is called
Rectangle constructor is called
Area is 15
Perimeter is 16
Rectangle destructor is called
Shape destructor is called
