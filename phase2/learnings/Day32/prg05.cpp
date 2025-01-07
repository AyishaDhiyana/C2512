//counter problem
//race condition example - more than two threads
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
const int NUM_OF_THREADS = 100 * 2;
const long long TIMES = 5000000LL / (NUM_OF_THREADS / 2);

long long count;


void counter() {
    for(long long I = 0; I < TIMES; I++) {
        count ++;
    }
}
int test() {
    count = 0;
    vector<thread> thrCounters;
    for(int I = 1; I <= NUM_OF_THREADS; I++)
    {
        thread thrCounter(counter);
        thrCounters.push_back(move(thrCounter));
    }
    for(int I = 1; I <= NUM_OF_THREADS; I++)
    {
        thrCounters[I-1].join();
    }
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
