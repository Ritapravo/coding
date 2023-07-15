#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int dp[101][100001];

int solve(int val[], int wt[], int n, int v){
    if(v==0 && n==0)
        return 0;
    if(n==0)
        return INT_MAX;
    if(dp[n][v]!=-1)
        return dp[n][v];
    if(val[n-1]>v)
        return dp[n][v] = solve(val, wt, n-1, v);
    else{
        return dp[n][v] = min(solve(val, wt, n-1, v), 
            wt[n-1]+solve(val, wt, n-1, v-val[n-1]));
    }
}

void code(){
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    int val[n], wt[n], max_val=0, max_wt=0;
    for(int i = 0; i<n; i++){
        cin>>wt[i]>>val[i];
        max_val += val[i];
        max_wt += wt[i];
    }
    if(max_wt<=w){
        cout<<max_val<<endl;
        return;
    }
    for(int v = max_val-1; v>=0; v--){
        if(solve(val, wt, n, v)<=w){
            cout<<v<<endl;
            return;
        }
    }
    cout<<"0"<<endl;
}

signed main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t;
    cin >> t;
    while(t--)
    code();
    return 0;
}
