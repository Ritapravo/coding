// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void graphInput (vector<int> [], int );




bool dfs (vector<int> adj[], vector<int> &visited, int node, int color){
    visited[node] = color;
    for(auto i: adj[node]){
        if(visited[i]==-1){
            if(!dfs(adj, visited, i, 1-color))
                return false;
        }
        if(visited[i]==color)
            return false;
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
	vector<int> visited(V, -1);
    for(int i = 0; i<V; i++){
        if(visited[i]==-1){
            if(!dfs(adj, visited, i, 0))
                return false;
        }
    }
    return true;
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin>>tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        graphInput(adj, E);
        cout<<isBipartite(V, adj)<<endl;
        // for(int i = 0; i<V; i++){
        //     for(auto it: adj[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        cout<<endl;
    }
    return 0;
}

void graphInput (vector<int> adj[], int m){
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}