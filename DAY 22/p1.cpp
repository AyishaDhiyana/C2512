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
--------------------------------------------------------------
//using pointers

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
        int id = 56;
        int* ptr = &id;
        cout << "id = " << id << endl;
        cout << "address = " << &id << endl;
        cout << "deref = " << *(&id) << endl;
        cout << "ref of deref = " << &(*(&id)) << endl;
        cout << "address of pointer = " << ptr << endl;
        cout << "ptr value return = " << *ptr << endl;
        return EXIT_SUCCESS;
}
-----------------------------------------------------------------
