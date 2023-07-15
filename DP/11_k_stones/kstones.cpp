#include<bits/stdc++.h>
using namespace std;


void code(){
    int n, k;
    cin>>n>>k;
    bool dp[n+1][k+1];
    int arr[n];
    for(int i = 0; i<n; i++)cin>>arr[i];
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=k; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            // else if(dp[i-1][j]==1)
            //     dp[i][j] = 1;
            else if(i==1){
                if(j-arr[i-1]>=0)
                    dp[i][j] = !dp[i][j-arr[i-1]];
                else 
                    dp[i][j] = dp[i-1][j];
            }
            else{
                if(j-arr[i-1]>=0)
                    dp[i][j] = (!dp[i][j-arr[i-1]]) || (!dp[i][j-arr[i-2]]);
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=k; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    string res = dp[n][k]==1?"First":"Second";
    cout<< res <<endl;
}

int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t; cin>>t;
    while(t--)
    code();
    return 0;
}
