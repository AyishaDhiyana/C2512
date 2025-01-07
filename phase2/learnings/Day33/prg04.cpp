//to find sum of salaries using custom parallel algorithm
//
//non-multi threaded code to find sum of salaries 
//future requirement: parallel algorithm
//multi threaded slices salaries array into 10 
//each slice appoint one thread to find sum 
//use sums array where number of sums is number of slices 
//each slice will have one-on-one element in sums to update sum 


#include<iostream>
#include<vector>

double findSum(std::vector<double> salaries)
{
    double sum = 0.0;
    for(auto e : salaries) {
        sum += e;
    }
    return sum;
}

int test() {
    std::vector<double> s;
    for(int I = 1; I <= 100; I++) {
        s.push_back((double)I);
    }

    double sum = findSum(s);
    std::cout << sum << std::endl;

    return 0;
}

int main() {
    int t = 15;
    while(t--) {
        test();
    }
    return 0;
}