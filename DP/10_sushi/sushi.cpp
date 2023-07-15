#include<bits/stdc++.h>
using namespace std;

double dp[301][301][301];

double solve( int a, int b, int c, int n){
    if(a==0 && b==0 && c==0)
        return dp[a][b][c] = 0;
    if(a+b+c>n)
        return 0;
    if(dp[a][b][c]!=-1)
        return dp[a][b][c];
    double m = 1;
    if(a>0) m += ((double)a/n)*solve(a-1, b, c, n);
    if(b>0) m += ((double)b/n)*solve(a+1, b-1,c,n);
    if(c>0) m += ((double)c/n)*solve(a, b+1,c-1,n);
    m = m*n/(a+b+c);
    return dp[a][b][c] = m;
    
}

void code(){
    cout<<setprecision(10)<<fixed;
    int n;
    cin>>n;
    for(int i = 0; i<=n; i++)
        for(int j = 0; j<=n; j++)
            for(int k = 0; k<=n; k++)
                dp[i][j][k] = -1;
    int arr[4] = {};
    for(int i = 0; i<n; i++){
        int c; cin>>c;
        arr[c]++;
    }
    double res = solve(arr[1], arr[2], arr[3], n);
    cout<<res<<endl;
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
