// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void graphInput (vector<int> [], int );

bool dfs(vector<int>adj[], vector<int>&visited, vector<int>&path_visited, int node){
    visited[node] = 1;
    path_visited[node] = 1;
    for(int i: adj[node]){
        if(!visited[i]){
            if(dfs(adj, visited, path_visited, i))
                return true;
        }
        if(visited[i] && path_visited[i]){
            return true;
        }
    }
    path_visited[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    vector<int> path_visited(V, 0);
    for(int i = 0; i<V; i++){
        if(!visited[i]){
            if(dfs(adj, visited, path_visited, i))
                return true;
        }
    }
    return false;
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
        cout<<isCyclic(V, adj)<<endl;
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