#include <iostream>
using namespace std;

class C2512Stack 
{
private:
    static const int _size = 100; // Maximum stack size
    double arr[_size];           // Array to store stack elements
    int _top;                    // Index of the top element

public:
    // Constructor 
    C2512Stack() : _top(0) {}

    void push(double data)
    {
        if (_top >= _size)
        {
            cout << "Stack Overflow: Cannot push onto a full stack." << endl;
            return;
        }
        arr[_top] = data;
        _top++;
    }

    void pop()
    {
        if (_top <= 0)
        {
            cout << "Stack Underflow: Cannot pop from an empty stack." << endl;
            return;
        }
        _top--;
    }

    double top()
    {
        if (_top <= 0)
        {
            cout << "Stack Underflow: No elements in the stack." << endl;
            return -1; 
        }
        return arr[_top - 1];
    }
};

int main()
{
    C2512Stack stack;

    stack.push(10.0);
    stack.push(12.0);
    stack.push(11.0);

    cout << stack.top() << endl; // Output: 11.0
    stack.pop();

    cout << stack.top() << endl; // Output: 12.0
    stack.pop();

    cout << stack.top() << endl; // Output: 10.0
    stack.pop();

    // This will show an underflow error
    cout << stack.top() << endl; // Error: Underflow
    stack.pop();

    return 0;
}
