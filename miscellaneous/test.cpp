#include<bits/stdc++.h>
using namespace std;


int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    cout<<"hello Ritoman";
    return 0;
}
