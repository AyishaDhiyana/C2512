#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
using namespace std;

void printTeam(vector<string> team) {
    for(auto player: team) {
        this_thread::sleep_for(chrono::milliseconds(1));
        cout << player;
    }
}

void geHealthcare() {
    vector<string> team {"ayisha ", "athira ", "dhaheen ", "nayana ", "abel "};
    printTeam(team);
}

void mediconnect() {
    vector<string> team {"vnkatesh ", "sooraj ", "nimisha ", "vishak ", "josh "};
    printTeam(team);
}

void automative() {
    vector<string> team {"minhaj ", "vinayak ", "sana ", "pitchmani "};
    printTeam(team);
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