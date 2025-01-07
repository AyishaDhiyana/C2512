//NOTE:: NOT DONE 
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <forward_list>
#include <set>
#include <thread>
#include <future>
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

    if (policy == MyExecPolicy::Seq) {
        return saFindSum(first, last, init);
    } else if (policy == MyExecPolicy::Par) {
        // Parallel algorithm
        auto distance = std::distance(first, last);
        const int maxThreads = std::thread::hardware_concurrency(); // Get number of threads supported by hardware
        const int numThreads = std::min(static_cast<int>(distance), maxThreads);
        const int chunkSize = distance / numThreads;

        std::vector<std::future<T>> futures;
        futures.reserve(numThreads);

        // Divide the work among threads
        auto chunkFirst = first;
        for (int i = 0; i < numThreads; ++i) {
            auto chunkLast = (i == numThreads - 1) ? last : std::next(chunkFirst, chunkSize);
            futures.push_back(std::async(std::launch::async, saFindSum, chunkFirst, chunkLast, T(0)));
            chunkFirst = chunkLast;
        }

        // Combine results from all threads
        T totalSum = init;
        for (auto& future : futures) {
            totalSum += future.get();
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
