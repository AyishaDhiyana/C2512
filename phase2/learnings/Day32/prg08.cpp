#include<iostream>
#include<queue>
#include<thread>
#include<chrono>
#include<mutex>
#include<condition_variable>
int MAX_SIZE = 5;
std::queue<long> products;
long product_id = 0L;

std::mutex mt;
std::condition_variable cv;

void producer() {    
    while(true) { 
        std::unique_lock<std::mutex> lock(mt); 
        //wait if cannot  !(products.size() < MAX_SIZE)
        //while(!(products.size() < MAX_SIZE)) { cv.wait(lock); }
        //auto predicate = []()->bool{ return (products.size() < MAX_SIZE); }; cv.wait(lock, predicate);
        cv.wait(lock, []()->bool{ return (products.size() < MAX_SIZE); });
        //can produce condition [products.size() < MAX_SIZE]
        product_id++;
        products.push(product_id);
        std::cout << "produced product is " << product_id << std::endl;

        //notify to consumers 
        cv.notify_all();
        //simulate by delay 
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void consumer() {
    while(true) { 
        std::unique_lock<std::mutex> lock(mt); 
        //wait if cannot        products.empty()
        //while(products.empty()) { cv.wait(lock); }
        cv.wait(lock,[](){ return !products.empty();});
        //can consume condition [!products.empty()]
        long product_id = products.front();
        products.pop();
        std::cout << "consumed product is " << product_id << std::endl;

        //notify to producers 
        cv.notify_all();
        //simulate by delay 
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::thread thrProducerOne(producer);
    std::thread thrProducerTwo(producer);
    std::thread thrConsumerOne(consumer);
    std::thread thrConsumerTwo(consumer);
    thrProducerOne.join();
    thrProducerTwo.join();
    thrConsumerOne.join();
    thrConsumerTwo.join();
    return 0;
}