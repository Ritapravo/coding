#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include <ctime>
using namespace std;
typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

void findEven (ull start, ull end){
    for(ull i = start; i<=end; i++){
        if((i&1)==0){
            EvenSum += i;
        }
    }
}

void findOdd (ull start, ull end){
    for(ull i = start; i<=end; i++){
        if((i&1)==1){
            OddSum += i;
        }
    }
}

int main(){
    ull start = 0, end = 190000000;
    // auto startTime = high_resolution_clock::now();

    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);
    
    t1.join();
    t2.join();

    // findOdd(start, end);
    // findEven(start, end);
    
    // auto stopTime = high_resolution_clock::now();
    // auto duration = duration_cast<microsecond>(stopTime-startTime);
    
    cout<<"OddSum : "<<OddSum<<endl;
    cout<<"EvenSum : "<<EvenSum<<endl;
    
    // cout<<duration.count()/100000 <<endl;
    return 0;
}
