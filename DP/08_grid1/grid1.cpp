#include<bits/stdc++.h>
using namespace std;


void solve(){
    int m, n;
    cin >> m >> n;
    int dp[m][n]={}, e = 1e9+7;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            char c;
            cin>>c;
            if(c=='#')
                dp[i][j] = 0;
            else if(i==0)
                dp[i][j] = j>0?dp[i][j-1]:1;
            else if(j==0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%e;
        }
    }
    cout<<dp[m-1][n-1]<<endl;
}

int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
