typedef-- alias name for the datatype (tag name)

Deadlock-
deadlock free version -- mutex1 & 2 will be locked in thread1 so that thread2 cant access it.

Shared mutex :
only one thread to write data at a time and multiple thread can read concurrently.
reader-writer lock pattern.
shared lock-- shared mutex.
reader - shared lock
writer - unique lock
==================================================================================================
#include<iostream>
#include<thread>
#include<shared_mutex>
#include<chrono>

long TIMES = 5000000L; // Total iterations for the counter
long count = 0; // Shared counter variable

std::shared_mutex mt; // Shared mutex for synchronizing access to count

void counter() {
    for(long I = 1; I <= TIMES; I++) {
        {
            std::shared_lock<std::shared_mutex> lock(mt); // Acquire shared lock
            count++; // Increment the counter
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
    }
}

void displayCount(int id) {
    for(long I = 1; I <= TIMES; I++) {
        {
            std::shared_lock<std::shared_mutex> lock(mt); // Acquire shared lock
            std::cout << "At " << id << ":" << count << std::endl; // Display the count
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
    }
}

int main() {
    std::thread thrCounter(counter); // Create thread for counter
    std::thread thrDisplay1(displayCount, 101); // Create thread for displaying count
    std::thread thrDisplay2(displayCount, 102); // Create another display thread
    std::thread thrDisplay3(displayCount, 103); // Create yet another display thread
    
    thrCounter.join(); // Wait for counter thread to finish
    thrDisplay1.join(); // Wait for display thread 1 to finish
    thrDisplay2.join(); // Wait for display thread 2 to finish
    thrDisplay3.join(); // Wait for display thread 3 to finish
    
    return 0; // Exit the program
}
============================================================================================
emplace_back -- automatically thread obj will be created and call push back function.
use instead of push_back
============================================================================================
//pools of thread

#include<iostream>
#include<thread>
#include<shared_mutex>
#include<chrono>
#include<vector>
long TIMES = 5000000L;
long count = 0;

std::shared_mutex mt;

void counter() {
    for(long I = 1; I <= TIMES; I++) {
        {
            std::shared_lock<std::shared_mutex> lock(mt);
            count++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void displayCount(int id) {
    for(long I = 1; I <= TIMES; I++) {
        {
            std::shared_lock<std::shared_mutex> lock(mt);
            std::cout << "At " << id << ":" << count << std::endl; 
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}



int main() {
    std::thread thrCounter(counter);
    std::vector<std::thread> thrDisplays;
    for(int I = 1; I <= 3; I++) {
        //thrDisplays.push_back(std::thread(displayCount, 101))
        thrDisplays.emplace_back(displayCount, 100 + I);
    }
    
    /*std::thread thrDisplay1(displayCount, 101);
    std::thread thrDisplay2(displayCount, 102);
    std::thread thrDisplay3(displayCount, 103);
    */
    
    thrCounter.join();
    for(int I = 1; I <= 3; I++) {
        thrDisplays[I].join();
    }
    /*
    thrDisplay1.join();
    thrDisplay2.join();
    thrDisplay3.join();
    */
    return 0;
}
===========================================================================
Atomic : 
automatic for mutex (lock)
wrapper for mutex & conditional variable 
member fns -- load, store, exchange.
atomic is faster compared to mutex
program:
instead of count ++ -- used store and load OR fetch_add
compare_exchange_strong --- same value will not update.

Memory order:
no order
relaxed, consume, acquire(wait), release(notify).
acquire(wait), release(notify) ensure syncronization btwn threads.
chance of race condition
hardware barrier -- avoid race condition.

Thread communicate via signals.
in vector -- the resource shared by one thread will not be same as the other thread.

Prog05:
sums[sliceIndex]--shared variable
findSumSlice--thread routine
5 threads we're defining
mtFindSum--multithread
emplace_back -- element in the vector -- obj construction & push_back(adding to the vector)
data , thread, results --  3 arrays
ref--pass by ref o/w pass by value.
----------------------------------------
//non-multi threaded code to find sum of salaries 
//future requirement: parallel algorithm

#include<iostream>
#include<vector>
#include<thread>

const int SIZE = 100;
const int SLICES = 5;

//thread routine for pools of thread
void findSumSlice(std::vector<double>& salaries, std::vector<double>& sums, int sliceIndex) { //thr routine // pools
    double sum = 0.0;
    int sliceSize = SIZE / SLICES; //num of elements in each slice //20
    int startIndex = sliceIndex * sliceSize;
    int endIndex = startIndex + sliceSize - 1;
    for(int I = startIndex; I <= endIndex; I++) {
        sum += salaries[I];
    }
    //
    sums[sliceIndex] = sum;
}

void mtFindSum(std::vector<double>& salaries, std::vector<double>& sums)
{
    std::vector<std::thread> workers; //pools of thread
    for(int sI = 0; sI < SLICES; sI++) {
        workers.emplace_back(findSumSlice,  
                std::ref(salaries),
                std::ref(sums),
                sI);
    }
    for(int sI = 0; sI < SLICES; sI++) { //pools of thread synchronized
        workers[sI].join();
    }
}

double findSum(std::vector<double>& salaries)
{
    std::vector<double> sums;
    for(int sI = 0; sI < SLICES; sI++) {
        sums.push_back(0.0);
    }

    /*
        threads to find sum via each slice 
    */
   mtFindSum(salaries, sums);

    double sum = 0.0;
    for(int sI = 0; sI < SLICES; sI++) {
        sum += sums[sI];
    } 
    return sum;
}

int test() {
    std::vector<double> s;
    for(int I = 1; I <= SIZE; I++) {
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
-------------------------------------------------------------
findSum is doing for the iterators not containers.
-------------------------------------------------------------
parallel algorithm:

prog07:
seq not avail in global section (with class)
only in MyExecPolicy
called strongly typed Enum.
made seq algorithm.
tfindSum -- thread
either seq or parallel is acheving.
inside threaded using seq algorithm.
result--reference.
============================================================
add promise & future -- header <future>
============================================================
#include<iostream>
#include<thread>
#include <future>

void add(double a, double b, std::promise<double> result) // thread routine
{
    double s = a + b; // Perform addition
    result.set_value(s); // Set the result in the promise
}

int main()
{
    double p = 10, q = 3, r = 4, m = 7; // Initialize variables for addition
    std::promise<double> result1_promise; // Create a promise for the first result
    std::promise<double> result2_promise; // Create a promise for the second result
    std::future<double> result1_future = result1_promise.get_future(); // Get future from promise
    std::future<double> result2_future = result2_promise.get_future(); // Get future from promise
    
    // Create threads to perform addition
    std::thread thr1(add, p, q, std::move(result1_promise)); // Thread for p + q
    std::thread thr2(add, r, m, std::move(result2_promise)); // Thread for r + m
    
    thr1.join(); // Wait for the first thread to finish
    thr2.join(); // Wait for the second thread to finish
    
    // Output the results
    std::cout << result1_future.get() << ", result 2 from promise = " << result2_future.get();
    return 0;
}

//move -- to pass the promise 
before move capture future object
ref instead of move -- 4 copies (prog012)
===============================================================================================
Async fn:

prog13:
future returned as async fn
2 diff threads-- auto 
add call internally.
delayed call -- differed policy
get -- add called
dont want thread -- go for defer
want thread -- go for async

#include<iostream>
#include<thread>
#include <future>

double add(double a, double b)//thread routine
{
    double s = a + b;
    return s;
}

int main()
{
    double p = 10, q = 3, r = 4, m = 7;
    
    auto future1 = std::async(add,p,q);
    auto future2 = std::async(add,r,m);
    
    std::cout << future1.get() << ", " << future2.get();
    return 0;
}
==========================================================
#include<thread>
#include<iostream>
#include<future>

double add(double a, double b) { //thr routine 
    double s = a + b;
    std::cout << "called inside add" << std::endl;
    return s;
}

int main() {
    double p = 10, q = 3, r = 4, m=7; //p+q, r+m // 13,11
    auto future1 = std::async(std::launch::async | std::launch::deferred, add,p,q); //policy=async | deferred
    auto future2 = std::async(std::launch::async | std::launch::deferred, add,r,m);
    std::cout << "Before get" << std::endl;
    
    std::cout << future1.get() << ", " << future2.get();
    return 0;
}
==================================================================================================================
