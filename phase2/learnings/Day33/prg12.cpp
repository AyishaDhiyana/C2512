#include<thread>
#include<iostream>
#include<future>


void add(double a, double b, std::promise<double> result) { //thr routine 
    double s = a + b;
    result.set_value(s);
}

int main() {
    double p = 10, q = 3, r = 4, m=7; //p+q, r+m // 13,11
    std::promise<double> result1_promise;
    std::promise<double> result2_promise;
    std::future<double> result1_future = result1_promise.get_future();
    std::future<double> result2_future = result2_promise.get_future();
    
    
    std::thread thr1(add, p, q, std::move(result1_promise));
    std::thread thr2(add, r, m, std::move(result2_promise));
    thr1.join();
    thr2.join();
    std::cout << result1_future.get() << ",result 2 from promise = " << result2_future.get();
    return 0;
}