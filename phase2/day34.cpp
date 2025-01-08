#include <iostream>
#include <unistd.h>

void parent()
{
    for(int i = 0; i < 10; i++)
    {
    std::cout << "Hello parent" << std::endl;
    sleep(1);
    }
}

void child(int id)
{
    for(int i = 0; i < 10; i++)
    {
    std::cout << "Hi child id = " << id << std::endl;
    sleep(1);
    }
}

int main()
{
    pid_t pid1 = fork();
    pid_t pid2 = fork();
    pid_t pid3 = fork();
    pid_t pid4 = fork();
    
    if(pid1 == 0)
    {
        child(1);
        return 0;
    }
    else if(pid2 == 0)
    {
        child(2);
        return 0;
    }
    else if(pid3 == 0)
    {
        child(3);
        return 0;
    }
    else if(pid4 == 0)
    {
        child(4);
        return 0;//success complettion of the process o/w hierarchial way happens not multiprocessing.
    }
    else 
    {
        parent();
    }
    return 0;
}
==========================================================================================================
#include <iostream>

class Rectangle
{
    private:
    
    double length;
    double breadth;
    
    public:
    
    Rectangle() {};
    Rectangle(int p_length, int p_breadth)
    {
        length = p_length;
        breadth = p_breadth;
    }
    Rectangle(Rectangle& other)
    {
        other.length = length;
        other.breadth = breadth;
    }
   Rectangle& operator=(const Rectangle& other)
   {
       this->length = other.length;
       this->breadth = other.breath;
       return *this; 
   }
    Rectangle(Rectangle&& other)
    {
        other.length = length;
        other.breadth = breadth;
        length = 0;
        breadth = 0;
        
    }
    Rectangle& operator=(Rectangle&& other)
    { 
        this->length = other.length; 
        this->breadth = other.breath; 
        other.length=0; other.breadth=0;
        return *this;
    }
}

int main()
{
    Rectangle r1;
    Rectangle r2(2, 4);
    Rectangle r3(r2);
    Rectangle r4(5, 6);
    Rectangle r5(move(r4));
    return 0;
}
 
