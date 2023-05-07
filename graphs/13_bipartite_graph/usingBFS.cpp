// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
// instead of taking color in the queue, you can simply get the color from visited[node]
// can use "color" as name of the vector instead of "visited"

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void graphInput (vector<int> [], int );


bool bfs (vector<int> adj[], vector<int> &visited, int i){
    queue<pair<int, int>> q;
    q.push({i, 0});
    visited[i] = 0;
    while(!q.empty()){
        int node = q.front().first;
        int color = q.front().second;
        q.pop();
        for (auto i: adj[node]){
            // cout<<"node "<<node<<" color "<<color<<" visited[i] "<<visited[i]<<endl;
            if(visited[i]==-1){
                visited[i] = 1-color;
                q.push({i, 1-color});
            }
            else if(visited[i]==color)
                return false;
        }
    }  
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
	vector<int> visited(V, -1);
    for(int i = 0; i<V; i++){
        if(visited[i]==-1){
            if(!bfs(adj, visited, i))
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