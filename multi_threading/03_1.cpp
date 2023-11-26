// Thread join

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include <ctime>
using namespace std;
typedef unsigned long long ull;

void run(int count){
    std::this_thread::sleep_for(chrono::seconds(3));
    while(count--)
        cout << "Ritoman" << endl;
}

int main(){
    std::thread t1 (run, 10);
    
    cout << "main function ()" << endl;
    t1.join();
    // this part after join will wait for the thread to execute 
    // double join will produce error
    
    // this will make sure that join is not called twice
    if(t1.joinable())
        t1.join();
    cout << "main after" << endl;
    return 0;
}