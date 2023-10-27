#include<bits/stdc++.h>
using namespace std;


int minExtraCoupons(vector<int> &coupons, int n, int p){
    int ind = 0, cnt = 0, reach = 0;
    sort(coupons.begin(), coupons.end());
    if(n>ind && coupons[ind]!=1){
        cnt++; reach = 1;
    }
    else if(n>ind && coupons[ind]==1){
        reach = 1; ind++;
    }
    if(n>ind && coupons[ind]!=2){
        cnt ++; reach = 3;
    }
    else if(n>ind && coupons[ind]==2){
        reach = 3; ind++;
    }
    int curr = 2;
    while(reach<p){
        if((ind >=n || reach < coupons[ind]-1 ) && reach < p ){
            cnt++;
            curr = reach + 1;
            reach = reach + curr;
        }
        else {
            curr = coupons[ind];
            reach += coupons[ind];
            ind ++;
        }
    }
    return cnt;
}



void code(){
    int n, p;
    cin >> n >> p;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cout<< minExtraCoupons(arr, n, p)<<endl;
}


int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input1.txt";
    freopen(inputPath.c_str(), "r", stdin);

    int t; 
    cin >> t;
    while(t--)
        code();
    return 0;
}