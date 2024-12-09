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

============================================================= 
                          SOLUTION
=============================================================

C++ CODE:

#include <iostream>
#include <cstdlib>

using namespace std;

class Shape
{
public:
    //constructor
    Shape()
    {
        cout << "Shape constructor is called" << endl;
    }

    //destructor
    virtual ~Shape()
    {
        cout << "Shape destructor is called" << endl;
    }

    //pure virtual behaviors
    virtual void calculateArea() = 0;
    virtual void calculatePerimeter() = 0;
};

class Rectangle : public Shape
{
public:
    int* length;
    int* breadth;
    //constructor
    Rectangle(const int lengthValue, const int breadthValue)
    {
        length = new int(lengthValue);
        breadth = new int(breadthValue);
        cout << "Rectangle constructor is called" << endl;
    }

    //destructor
    ~Rectangle()
    {
        delete length;
        delete breadth;
        cout << "Rectangle destructor is called" << endl;
    }

    //behaviors
    void calculateArea() override
    {
        float area = ((*length) * (*breadth));
        cout << "Area is " << area << endl;
    }

    void calculatePerimeter() override
    {
        float perimeter = 2 * (*length + *breadth);
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

--------------------------------OUTPUT---------------------------------

Shape constructor is called
Rectangle constructor is called
Area is 15
Perimeter is 16
Rectangle destructor is called
Shape destructor is called
