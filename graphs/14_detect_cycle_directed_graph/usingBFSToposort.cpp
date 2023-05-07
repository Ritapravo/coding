// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// This is exacty similat to topological sort using Kahn's algorithm using BFS.
// In Kahn's algo, if there is a cycle, the queue will get empty even before
// all nodes are once pushed to queue because it pushes to the queue only when 
// the in-degree is 0. So, the number of elements in the topological sort 
// result will not be equal(less) to the number of vertices, if there is a cycle.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void graphInput (vector<int> [], int );



bool isCyclic(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);
    for(int i = 0; i<V; i++){
        for(int j: adj[i])
            inDegree[j] += 1;
    }
    queue<int> q;
    for(int i = 0; i<V; i++){
        if(inDegree[i]==0)
            q.push(i);   
    }
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count += 1;
        for(int i: adj[node]){ 
            inDegree[i] -= 1;
            if(inDegree[i]==0){
                q.push(i);
            }
        }
    }
    if(count==V) return false;
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