// https://practice.geeksforgeeks.org/problems/topological-sort/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void graphInput (vector<int> [], int );

void dfs(vector<int>adj[], vector<int>&visited, vector<int>&res, int node){
    visited[node] = 1;
    for(auto i : adj[node]){
        if(!visited[i])
            dfs(adj, visited, res, i);
    }
    res.push_back(node);
}


vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> visited(V, 0);
    vector<int> res;
    for(int i = 0; i<V; i++){
        if(!visited[i]){
            dfs(adj, visited, res, i);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin>>tc;
    while(tc--){
        int V, E;
        cin >> E >> V;
        vector<int> adj[V];
        graphInput(adj, E);
        vector<int> res = topoSort(V, adj);
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