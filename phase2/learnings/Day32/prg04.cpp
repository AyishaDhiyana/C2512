//counter problem
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
int test() {
    count = 0;
    thread thrCounter1(counter1);
    thread thrCounter2(counter2);
    thrCounter1.join();
    thrCounter2.join();
    cout << count;
    return 0;
}

int main() {
    int t = 15;
    while(t--) {
        std::cout << endl;
        test();
    }
    return 0;
}
