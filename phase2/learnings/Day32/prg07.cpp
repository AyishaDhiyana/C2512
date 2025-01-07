// producer - consumer problem
// many producers / many consumers 
// buffer - queue 

#include<iostream>
#include<queue>
#include<thread>
#include<mutex>
#include<chrono>
#include<condition_variable>

int MAX_SIZE = 5;
std::queue<long> products;
std::mutex mt;
std::condition_variable cv;

void producer() {
    long product_id = 0;
    while(true) {
        std::unique_lock<std::mutex> lock(mt);

        while(!(products.size() < MAX_SIZE)) { //products.size() == MAX_SIZE
            cv.wait(lock); 
        }

        product_id++;
        products.push(product_id);
        std::cout << "produced product is " << product_id << std::endl;
        //notify to consumers
        cv.notify_all();

        //real time sumulation via sleep 
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void consumer() {
    while(true) {
        std::unique_lock<std::mutex> lock(mt);
        while(products.empty()) {
            cv.wait(lock); 
        }

        long product_id = products.front();
        products.pop();
        std::cout << "consumed product is " << product_id << std::endl;

        // notify to producers
        cv.notify_all();
        //real time sumulation via sleep 
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}

void test() {
    std::thread thrProducerOne(producer);
    std::thread thrProducerTwo(producer);
    std::thread thrConsumerOne(consumer);
    std::thread thrConsumerTwo(consumer);

    thrProducerOne.join();
    thrProducerTwo.join();
    thrConsumerOne.join();
    thrConsumerTwo.join();
}

int main() {
    test();
}