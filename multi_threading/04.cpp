// Mutex in C++ 
// Mutex : Mutual Exclusion

// RACE CONDITION
// 0. Race condition is a situation where two or more threads/processes happened to change a common data 
// at the same time 
// 1. If there is a RACE condition then we have to protect it and the protected section is called critical section/region


// MUTEX 
// 0. Mutex is a lock to avoid race condition
// 1. We use lock() , unlock() on mutex to avoid race condition

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<mutex>
#include <ctime>
using namespace std;
typedef unsigned long long ull;

int myAccount = 0;
std::mutex m;

void addMoney(){
    m.lock();
    ++myAccount;
    m.unlock();
}

int main(){
    std::thread t1(addMoney);
    std::thread t2(addMoney);
    
    t1.join();
    t2.join();
    
    cout<<myAccount<<endl;
    
    return 0;
} 