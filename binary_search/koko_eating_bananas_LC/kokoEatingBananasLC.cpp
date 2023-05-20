// https://leetcode.com/problems/koko-eating-bananas/description/

#include<bits/stdc++.h>
using namespace std;

int findTime (vector<int> &arr, int k){
    int res = 0;
    for(int it: arr){
        double temp = (double)it/k;
        res += ceil(temp);
    }
    return res;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = 1e9;

    while(low<=high){
        int k = low + (high-low)/2;
        int timeRequired = findTime(piles, k);
        // cout<<timeRequired<<endl;
        
        if(timeRequired > h){
            low = k + 1;
        }
        else {
            high = k - 1;
        }
    }
    return low;
}

signed main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin>>tc;
    while(tc--){
        int h, n;
        cin >> n>> h;
        vector<int> piles(n);
        for(int i = 0; i<n; i++){cin>>piles[i];}
        int ans = minEatingSpeed(piles, h);
        cout<<ans<<endl<<endl;
    }
    return 0;
}
