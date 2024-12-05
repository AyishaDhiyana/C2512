//ref, dref etc..
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
        int id = 56;

        cout << "id = " << id << endl;
        cout << "address = " << &id << endl;
        cout << "deref = " << *(&id) << endl;
        cout << "ref of deref = " << &(*(&id)) << endl;
        return EXIT_SUCCESS;
}
