#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int>adj[], vector<int> &vis, int node){
    if(adj[node].size()==0)
        return 0;
    if(vis[node])
        return vis[node];
    int m = 0;
    for(int i:adj[node]){
        m = max(m, dfs(adj, vis, i));  
    }
    vis[node] = m+1;
    return m+1;
}


int main(){
    int n, m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    vector<int> vis(n, 0);
    int res = 0;
    for(int i = 0; i<n; i++){
        if(!vis[i])
            res = max(res,dfs(adj, vis, i));
    }
    // for(int i = 0; i<n; i++){
    //     cout<<vis[i]<<" ";
    // }
    cout<<res<<endl;
    return 0;
}
