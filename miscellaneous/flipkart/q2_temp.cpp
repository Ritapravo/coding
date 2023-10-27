#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &arr, int k){
    int n = arr.size();
    int res = INT_MAX, curr = 0;
    
    int low = 0, high = k-1, mid = low + (high-low+1)/2;
    for(int i = 0; i<k; i++)
        curr += abs(arr[i]-arr[mid]-(i-mid));

    res = min(res, curr);

    while(high<n-1){
        int temp = k%2 == 1 ? arr[mid]+arr[mid+1] : 2*arr[mid];
        curr = curr + arr[low] + arr[high+1] - temp;
        res = min(res, curr);
        low ++; high ++; mid = low + (high-low+1)/2; 
    }
    return res;
}


int minSwaps(vector<int> &arr, int n, int k){
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i<n; i++){
        mp[arr[i]].push_back(i);
    }
    // for(auto it: mp){
    //     cout<< it.first <<" -> ";
    //     for(auto ind: it.second){
    //         cout << ind <<" ";
    //     }
    //     cout << endl;
    // }
    int res = INT_MAX;
    for(auto it: mp){
        if(it.second.size()>=k){
            res = min(res, solve(it.second, k));
        }
    }
    return res;
}

void code(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << "ans = " << minSwaps(arr, n, k) << endl;
}


int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input2.txt";
    freopen(inputPath.c_str(), "r", stdin);

    int t; 
    cin >> t;
    while(t--)
        code();
    return 0;
}