//using extern keyword

---------------------ext.cpp---------------------  
#include <iostream>
#include "ext.h"

using namespace std;

extern string username;

void displayUsername()
{
        cout << "Username: " << username << endl;
}
--------------------------main.cpp-----------------------
#include <iostream>
#include <cstdlib>
#include <string>
#include "ext.h"

using namespace std;

string username = "Ayisha";

int main()
{
        int id = 12;

        displayUsername();

        cout << "id= " << id << endl;

        return EXIT_SUCCESS;
}
---------------------ext.h--------------------------
#pragma once

void displayUsername();
