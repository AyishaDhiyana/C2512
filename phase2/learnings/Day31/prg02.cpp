#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void geHealthcare() {
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "ayisha ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "athira ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "dhaheen ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "nayana ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "abel ";
}
void mediconnect() {
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "vnkatesh ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "sooraj ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "nimisha ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "vishak ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "josh ";
}
void automative() {
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "minhaj ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "vinayak ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "sana ";
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << "pitchumani ";
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