// Types of thread creation in C++
// 5 different types 

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include <ctime>
using namespace std;
typedef unsigned long long ull;

void fun(int x){
    while(x -- > 0){
        cout << x << endl;
    }
}

class Base {
public:
    void operator () (int x){
        while( x-- > 0){
            cout << x << endl;
        }
    }        
};

class Base2{
public:
    void run (int x){
        while(x-- >0){
            cout << x << endl;
        }
    }        
};

class Base3{
public:
    static void run (int x){
        while(x-- >0){
            cout << x << endl;
        }
    }  
};


int main(){
    
    // first type
    std::thread t1(fun, 11);
    std::thread t2(fun, 10);
    
    // second type - using lambda function
    auto fun = [](int x){
        while(x-- > 0){
            cout << x << endl;
        }
    };
    
    std:: thread t3(fun, 10);
    
    std:: thread t4([](int x){
        while(x-- > 0){
            cout << x << endl;
        }
    }, 10);
    
    // 3rd type - Functor( Function Object )
    
    std::thread t5(Base(), 10);
    
    // 4th type - Non-static member Function
    Base2 b2;
    std::thread t6(&Base2::run, &b2, 10);
        // (address of the function, addres of the object, parameter)
        
    // 5th type - static member function
    
    Base3 b3;
    std::thread t7(&Base3::run, 10);
    
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    return 0;
}