#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], vector<int> & vis, int mask, int node, int color){
    vis[node] = color;
    for(auto it: adj[node]){
        if(!(mask & (1<<it))) continue;
        if(vis[it]==-1){
            if(dfs(adj, vis, mask, it, 1-color)==false)
                return false;
        }
        else if(vis[it]==color)
            return false;
    }
    return true;
}

bool isBipartite(vector<int> adj[], int n, int mask){
    vector<int> vis(n, -1);
    for(int i = 0; i<n; i++){
    
        if(vis[i]==-1 && (mask & (1<<i))){
            if(dfs(adj, vis, mask, i, 0)==false)
                return false;
        }
    }
    return true;
}


int code(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    int mask = (1<<n)-1, ans = 0;
    for(int i = 0; i<(1<<n); i++){
        
        if(isBipartite(adj, n, i)){
            int remaining = __builtin_popcount(i);
            ans = max(ans, remaining);
        }
    }
    return ans;
}


int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t; 
    cin >> t;
    while(t--){
        int ans = code();
        cout<< ans << endl;
    }
    return 0;
}
