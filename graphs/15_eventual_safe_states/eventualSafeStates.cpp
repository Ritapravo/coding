// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void graphInput (vector<int> [], int );

bool dfs(vector<int>adj[], vector<int>&visited, vector<int>&path_visited, vector<int>&safe_nodes, int node){
    visited[node] = 1;
    path_visited[node] = 1;
    bool res = false;
    for(int i: adj[node]){
        if(!visited[i]){
            res = res || dfs(adj, visited, path_visited, safe_nodes, i);     
        }
        if(visited[i] && path_visited[i]){
            return true;
        }
    }
    if(!res) safe_nodes.push_back(node);
    path_visited[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    vector<int> path_visited(V, 0);
    vector<int> safe_nodes;
    for(int i = 0; i<V; i++){
        if(!visited[i]){
            dfs(adj, visited, path_visited, safe_nodes, i);
        }
    }
    sort(safe_nodes.begin(), safe_nodes.end());
    return safe_nodes;
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
        vector<int> res = eventualSafeNodes(V, adj);
        for(auto it: res)
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}

void graphInput (vector<int> adj[], int m){
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v ;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
}