#include<bits/stdc++.h>
using namespace std;



void solve(vector<vector<double>> &adj, vector<double> &ans, int n, int currentNode, int time, double p ){
    // cout<< currentNode<<" ";
    if(time<=0){
        ans[currentNode] += p;
        return ;
    }
    for(int i = 1; i<=n; i++){
        if(adj[currentNode][i]!=0){
            solve(adj, ans, n, i, time-10,(double)p*adj[currentNode][i]);
        }
    }
}



void code(){
    int n, m, time;
    cin >> n >> m >> time;
    vector<vector<double>>adj(n+1, vector<double> (n+1, 0.0));
    vector<double> ans(n+1, 0.0);
    for(int i = 0; i<m; i++){
        int a, b; 
        double c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    solve(adj, ans, n, 1, time, 1.0);
    double maxp = 0;
    int maxi = 0;
    for(int i =1; i<=n; i++){
        cout<< ans[i]<<" ";
        if(ans[i]>maxp){
            maxp = ans[i];
            maxi = i;
        }
    }
    cout<< maxi <<" "<<maxp<<endl;
}




int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input2.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t; cin>>t;
    while(t--)
        code();
    return 0;
}