// Try lock - if mutex is not able to get the lock, it will not get blocked, so non-blocking
// so here, if we run multiple times, the output will be different

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

void addMoney(int times){
    for(int i = 1; i<=times; i++){
        if(m.try_lock()){
            ++myAccount;
            m.unlock();
        }
    }
}

int main(){
    std::thread t1(addMoney, 100000);
    std::thread t2(addMoney, 100000);
    
    t1.join();
    t2.join();
    
    cout<<myAccount<<endl;
    
    return 0;
}