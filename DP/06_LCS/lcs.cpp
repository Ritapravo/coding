#include<bits/stdc++.h>
using namespace std;


int main(){
    string s, t;
    cin >> s >> t;
    int n1 = s.size(), n2 = t.size();
    int dp[n1+1][n2+1];
    for(int i = 0; i<=n1; i++){
        for(int j = 0; j<=n2; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(s[i-1]==t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string res(dp[n1][n2], '#');
    int i = n1, j = n2, k = dp[n1][n2];
    while(i>0 && j>0 ){
        if(s[i-1]==t[j-1]){
            i--; j--;
            res[--k]=s[i];
        }
        else if(dp[i][j]==dp[i-1][j])
            i--;
        else
            j--;
    }
    cout<<res<<endl;
    return 0;
}
