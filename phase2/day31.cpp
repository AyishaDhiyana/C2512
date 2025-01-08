#include <iostream>
#include <thread>

using namespace std;

void sayHi()
{
    cout << "Hi World" << endl;
}

void sayGoodAfternoon()
{
    cout << "Good Afternoon" << endl;
}

int main()
{
    thread thrSayHi(sayHi);
    thrSayHi.join();
    thread thrSayGoodAfternoon(sayGoodAfternoon);
    thrSayGoodAfternoon.join();
    
    cout << "Hello World";
    return 0;
}
=======================================================

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void automotive(){
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Sana" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Vinayak" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Pitchumani" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Minhaj" << endl;
}

void healthCare()
{
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Ayisha" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Abel" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Nayana" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Daheen" << endl;
}

int main()
{
    thread thautomative(automotive);
    thautomative.join();
    thread thhealthCare(healthCare);
    thhealthCare.join();
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Sooraj" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Vishakh" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Nimisha" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Venktesh" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Josh" << endl;
    cout << "Hello World";
    return 0;
}
====================================================
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void automotive(){
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Sana" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Vinayak" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Pitchumani" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Minhaj" << endl;
}

void healthCare()
{
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Ayisha" << endl;
    
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Abel" << endl;
    
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Nayana" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Daheen" << endl;
}

int main()
{
    thread thautomative(automotive);
    thautomative.detach();
    thread thhealthCare(healthCare);
    thhealthCare.detach();
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Sooraj" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Vishakh" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Nimisha" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Venktesh" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Josh" << endl;
    cout << "Hello World";
    return 0;
}
=================================================

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void automotive(){
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Sana" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Vinayak" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Pitchumani" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Minhaj" << endl;
}

void healthCare()
{
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Ayisha" << endl;
    
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Abel" << endl;
    
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Nayana" << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Daheen" << endl;
}

int main()
{
    thread thautomative(automotive);
    thautomative.detach();
    thread thhealthCare(healthCare);
    thhealthCare.detach();
    
    //this_thread::sleep_for(chrono::seconds(1));
    cout << "Sooraj" << endl;
    
    //this_thread::sleep_for(chrono::seconds(1));
    cout << "Vishakh" << endl;
    
    //this_thread::sleep_for(chrono::seconds(1));
    cout << "Nimisha" << endl;
    
    //this_thread::sleep_for(chrono::seconds(1));
    cout << "Venktesh" << endl;
    
    //this_thread::sleep_for(chrono::seconds(1));
    cout << "Josh" << endl;
    
    cout << "Hello World";
    return 0;
}
====================================================

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void automotive()
{
    vector<string> team {"Sana ", "Vinayak ", "Pitchumani ", "Minhaj " };
    for(auto members : team)
    {
    this_thread::sleep_for(chrono::seconds(1));
    cout << members;
    }
}
    
void healthCare()
{
     vector<string> team {"Ayisha ", "Abel ", "Nayana ", "Daheen " };
    for(auto members : team)
    {
    this_thread::sleep_for(chrono::seconds(1));
    cout << members;
    }
   
}

void medical()
{
 vector<string> team {"Sooraj ", "Nimisha ", "Venkatesh ", "Josh " , "Vishakh "};
    for(auto members : team)
    {
    this_thread::sleep_for(chrono::seconds(1));
    cout << members;
    }
}

int main()
{
    thread thautomative(automotive);
    thread thhealthCare(healthCare);
    thautomative.join();
    thhealthCare.join();
    automotive();
    
    cout << "Hello World ";
    return 0;
}
=========================================================================

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void automotive()
{
    vector<string> team {"Sana ", "Vinayak ", "Pitchumani ", "Minhaj " };
    for(auto members : team)
    {
    this_thread::sleep_for(chrono::seconds(1));
    cout << members;
    }
}
    
void healthCare()
{
     vector<string> team {"Ayisha ", "Abel ", "Nayana ", "Daheen " };
    for(auto members : team)
    {
    this_thread::sleep_for(chrono::seconds(1));
    cout << members;
    }
   
}

void medical()
{
 vector<string> team {"Sooraj ", "Nimisha ", "Venkatesh ", "Josh " , "Vishakh "};
    for(auto members : team)
    {
    this_thread::sleep_for(chrono::seconds(1));
    cout << members;
    }
}

int main()
{
    thread thautomative(automotive);
    thread thhealthCare(healthCare);
    thautomative.detach();
    thhealthCare.detach();
    automotive();
    
    cout << "Hello World ";
    return 0;
}
===============================================================

