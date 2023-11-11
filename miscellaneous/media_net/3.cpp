#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 9;
vector<int> adj[mx];
vector<int> in(mx) , out(mx) , arr(mx);
int ty = 0 ;

void dfs(int s , int pa=-1){
    in[s] = ++ty;
    arr[ty] = s;
    for (int x : adj[s])
    {
        if(x!=pa){
            dfs(x,s);
        }
    }
    out[s] = ty;
}

int solve(vector<int> &a,vector<int>& b){
    int n = a.size();
    int u,v;
    for(int i = 0 ; i < n ;i++){
        u = a[i] , v = b[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    int sum = 0 , mod = 1e9+7;
    for(int i = 1;i <= n ; i++){
        for(int j = in[i]; j <= out[i]; j++){
            if(arr[j] > i)sum = (sum + 1)%mod;
        }
    }
    
    return sum;
}

void code(){
    int n; 
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++){
        cin >> a[i] >> b[i];
    }
    cout<< solve(a, b)<<endl;
}

int main()
{
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input3.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t; cin >> t;
    while(t--)
        code();
    return 0;
}