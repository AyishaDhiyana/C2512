#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
using namespace std;

vector<float> temperatures;
float min1, min2;

int randNum(int start, int end) {
    int diff = (end - start); 
    int num = ((rand() % diff) + start);
    return num;
}

void slice1Min() {
    min1 = 111;
    long long endIndex = temperatures.size() / 2;
    for(long long I = 0; I < endIndex; I++) { 
        if(temperatures[I] < min1) { 
            min1 = temperatures[I];
        }
    }
}
void slice2Min() {
    min2 = 111;
    long long startIndex = temperatures.size() / 2 + 1;
    for(long long I = startIndex; I < temperatures.size(); I++) { 
        if(temperatures[I] < min2) { 
            min2 = temperatures[I];
        }
    }
}
int main() {
    srand(static_cast<unsigned>(time(0)));
    for(long long I = 1; I <= 6LL; I++) { //100000000LL
        float temperature = randNum(95, 110);
        temperatures.push_back(temperature);
    }

    thread thrSlice1Min(slice1Min);
    thread thrSlice2Min(slice2Min);
    thrSlice1Min.join();
    thrSlice2Min.join();
    cout << min1 << "," << min2 << endl;
    float min = min1 < min2 ? min1 : min2;
    cout << min;
    return 0;
}