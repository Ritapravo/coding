// https://practice.geeksforgeeks.org/problems/topological-sort/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void graphInput (vector<int> [], int );


vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> inDegree(V, 0);
    for(int i = 0; i<V; i++){
        for(int j: adj[i])
            inDegree[j] += 1;
    }
    vector<int> res;
    queue<int> q;
    for(int i = 0; i<V; i++){
        if(inDegree[i]==0)
            q.push(i);   
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(int i: adj[node]){ 
            inDegree[i] -= 1;
            if(inDegree[i]==0){
                q.push(i);
            }
        }
    }
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