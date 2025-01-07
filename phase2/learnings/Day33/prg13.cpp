#include<thread>
#include<iostream>
#include<future>


double add(double a, double b) { //thr routine 
    double s = a + b;
    //std::cout << "called inside add" << std::endl;
    return s;
}

int main() {
    double p = 10, q = 3, r = 4, m=7; //p+q, r+m // 13,11
    auto future1 = std::async(/*std::launch::async | std::launch::deferred,*/ add,p,q); //policy=async | deferred
    auto future2 = std::async(/*std::launch::async | std::launch::deferred,*/ add,r,m);
    //td::cout << "Before get" << std::endl;
    std::cout << future1.get() << ", " << future2.get();
    return 0;
}