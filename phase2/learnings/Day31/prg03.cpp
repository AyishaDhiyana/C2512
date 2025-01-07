#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

void geHealthcare() {
    fstream fout("ge.txt", ios::out | ios::trunc) ;
    
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "ayisha ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "athira ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "dhaheen ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "nayana ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "abel ";
    
    fout.close();
}
void mediconnect() {
    fstream fout("medi.txt", ios::out  | ios::trunc);
    
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "vnkatesh ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "sooraj ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "nimisha ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "vishak ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "josh ";
    
    fout.close();
}
void automative() {
    fstream fout("auto.txt", ios::out | ios::trunc);
    
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "minhaj ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "vinayak ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "sana ";
    this_thread::sleep_for(chrono::milliseconds(1));
    fout << "pitchmani ";
    
    fout.close();
}
int main()
{
    thread thrGeHealthcare(geHealthcare);
    thread thrMediconnect(mediconnect);
    
    thrGeHealthcare.join();
    thrMediconnect.join();
    //this_thread::sleep_for(chrono::milliseconds(1));
    automative();
    return 0;
}