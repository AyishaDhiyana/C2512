#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
using namespace std;

void geHealthcare() {
    vector<string> team {"ayisha ", "athira ", "dhaheen ", "nayana ", "abel "};
    for(auto player: team) {
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << player;
    }
}

void mediconnect() {
    vector<string> team {"vnkatesh ", "sooraj ", "nimisha ", "vishak ", "josh "};
    for(auto player: team) {
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << player;
    }
}

void automative() {
    vector<string> team {"minhaj ", "vinayak ", "sana ", "pitchmani "};
    for(auto player: team) {
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << player;
    }
}

int main()
{
    thread thrGeHealthcare(geHealthcare);
    thread thrMediconnect(mediconnect);
    thrGeHealthcare.join();
    thrMediconnect.join();
    automative();
    return 0;
}