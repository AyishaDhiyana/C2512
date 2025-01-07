#include<thread>
#include<iostream>

void add(double a, double b, double& result) { //thr routine 
    double s = a + b;
    result = s;
}

int main() {
    double p = 10, q = 3, r = 4, m=7; //p+q, r+m // 13,11
    double result1, result2; 
    std::thread thr1(add, p, q, std::ref(result1));//p and q are args to the thr, result1 is return val out of thread 
    std::thread thr2(add, r, m, std::ref(result2));
    thr1.join();
    thr2.join();
    std::cout << result1 << "," << result2;
    return 0;
}