//race condition example
#include <iostream>
#include <thread>
using namespace std;

const long long TIMES = 5000000LL;

long long count;


void counter1() {
    for(long long I = 0; I < TIMES; I++) {
        count ++;
    }
}
void counter2() {
    for(long long I = 0; I < TIMES; I++) {
        count ++;
    }
}
int main() {
    thread thrCounter1(counter1);
    thread thrCounter2(counter2);
    thrCounter1.join();
    thrCounter2.join();
    cout << count;
    return 0;
}