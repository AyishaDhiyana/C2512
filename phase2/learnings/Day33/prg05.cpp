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