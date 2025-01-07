//race condition example - fix via atomic ops
#include <iostream>
#include <thread>
#include <atomic>

const long long TIMES = 5000000LL;

std::atomic<long long> count = 0LL;


void counter1() {
    for(long long I = 0; I < TIMES; I++) {                  
        //count.store(count.load() + 1);
        count.fetch_add(1);
    }
}
void counter2() {
    for(long long I = 0; I < TIMES; I++) {
        count.fetch_add(1);
    }
}
int test() {
    count = 0;
    std::thread thrCounter1(counter1);
    std::thread thrCounter2(counter2);
    thrCounter1.join();
    thrCounter2.join();
    std::cout << count.load();
    return 0;
}

int main() {
    int t = 15;
    while(t--) {
        std::cout << std::endl;
        test();
    }
    return 0;
}
