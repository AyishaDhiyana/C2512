//Parallel algo is optimized here
//NOTE:: NOT DONE 

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <forward_list>
#include <set>
#include <thread>
#include <iterator>

enum class MyExecPolicy {
    Seq = 1, Par = 2
};

template<class InputIt, class T> 
T findSum(InputIt first, InputIt last, T init, MyExecPolicy policy = MyExecPolicy::Seq) {
    // Sequential algorithm
    auto saFindSum = [](InputIt first, InputIt last, T init) -> T {
        T sum = init;
        for (auto it = first; it != last; ++it) {
            sum += *it;
        }
        return sum;
    };
    auto tFindSum = [saFindSum](InputIt first, InputIt last, T init, T& result) -> void {
        T sum = saFindSum(first, last, init);
        //std::cout << "Parallel algo" << std::endl;
        result = sum;
    };
    if (policy == MyExecPolicy::Seq) {
        return saFindSum(first, last, init);
    } else if (policy == MyExecPolicy::Par) {
        // Parallel algorithm
        auto distance = std::distance(first, last);
        const int maxThreads = std::thread::hardware_concurrency(); // Get number of threads supported by hardware
        const int numThreads = std::min(static_cast<int>(distance), maxThreads);//slices
        const int chunkSize = distance / numThreads; //slice_size 
        std::cout << distance << "," << maxThreads 
                         << "," << numThreads 
                         << "," << chunkSize << std::endl; 
        std::vector<std::thread> workers;
        std::vector<T> results;
        auto chunkFirst = first;
        for (int i = 0; i < numThreads; ++i) {
            auto chunkLast = (i == numThreads - 1) ? last : std::next(chunkFirst, chunkSize);
            std::cout << chunkSize << "+chunks:" << std::distance(chunkFirst, chunkLast) << std::endl;
            results.push_back(init);
            workers.emplace_back(tFindSum, chunkFirst, chunkLast, init, std::ref(results[i]));
        }
        for (int i = 0; i < numThreads; ++i) {
            workers[i].join();
        }
        T totalSum = init;
        for (int i = 0; i < numThreads; ++i) {
            std::cout << "total at " << i << ":" << results[i] << std::endl;
            totalSum = totalSum + results[i];
        }       

        return totalSum;
    }

    return init; // Default case (should not happen)
}

int test() {
    std::vector<double> v {1, 2, 3, 4, 5}; // 15
    std::deque<double> d {1, 2, 3, 4, 5}; // 15
    std::list<double> l {1, 2, 3, 4, 5}; // 15
    std::array<double, 5> a {1, 2, 3, 4, 5}; // 15
    std::forward_list<double> fl {1, 2, 3, 4, 5}; // 15
    std::set<double> s {1, 2, 3, 4, 5}; // 15

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
    while (t--) {
        test();
    }
    return 0;
}

