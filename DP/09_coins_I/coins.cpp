#include<bits/stdc++.h>
using namespace std;

double dp[3000][3000];

double solve(double p[], int n, int k, int c){
    if(n==0 && k>=c)
        return 1;
    else if(n==0)
        return 0;
    if(dp[n][k]!=-1)
        return dp[n][k];
    else{
        double m = p[n-1]*solve(p, n-1, k+1, c) + 
            (1-p[n-1])*solve(p, n-1, k, c);
        return dp[n][k] = m;
    }
}

void code(){
    int n;
    cin>>n;
    int k = n/2 + 1;
    double p[n];
    for(int i = 0; i<=n; i++)
        for(int j = 0; j<=n; j++)
            dp[i][j] = -1;
    for(int i = 0; i<n; i++)cin>>p[i];
    double res = solve(p,n,0,k);
    cout<< setprecision(10) << res<<endl;
}

int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t;
    cin>>t;
    while(t--)
    code();
    return 0;
}
