//to find sum of objects using sequential algorithm
//for any container

#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<array>
#include<forward_list>
#include<set>
#include<thread>

enum class MyExecPolicy {
    Seq = 1, Par = 2
};

template<class InputIt, class T> 
T findSum(InputIt first, InputIt last, T init, MyExecPolicy policy = MyExecPolicy::Seq)
{
    auto saFindSum = [](InputIt first, InputIt last, T init) -> T {
        T sum = init;
        for(auto it = first; it != last; it++) {
            sum = sum + (*it);
        }
        return sum;
    };
    auto tFindSum = [saFindSum](InputIt first, InputIt last, T init, T& result) -> void {
        T sum = saFindSum(first, last, init);
        //std::cout << "Parallel algo" << std::endl;
        result = sum;
    };

    T s = init;
    if(MyExecPolicy::Seq == policy) {
        s = saFindSum(first, last, init);
    } else if(MyExecPolicy::Par == policy) {
        std::thread thr(tFindSum, first, last, init, std::ref(s));
        thr.join();
    }
    return s;
}

int test() {
    std::vector<double> v {1, 2, 3, 4, 5}; //15
    std::deque<double> d {1, 2, 3, 4, 5}; //15
    std::list<double> l {1, 2, 3, 4, 5}; //15
    std::array<double, 5> a{1, 2, 3, 4, 5}; //15
    std::forward_list<double> fl {1, 2, 3, 4, 5}; //15
    std::set<double> s {1, 2, 3, 4, 5}; //15

    std::cout << findSum(v.begin(), v.end(), 0.0, MyExecPolicy::Par) << std::endl;
    std::cout << findSum(d.begin(), d.end(), 0.0) << std::endl;
    std::cout << findSum(l.begin(), l.end(), 0.0) << std::endl;
    std::cout << findSum(a.begin(), a.end(), 0.0) << std::endl;
    std::cout << findSum(fl.begin(), fl.end(), 0.0) << std::endl;
    std::cout << findSum(s.begin(), s.end(), 0.0) << std::endl;

    return 0;
}

int main() {
    int t = 1;
    while(t--) {
        test();
    }
    return 0;
}