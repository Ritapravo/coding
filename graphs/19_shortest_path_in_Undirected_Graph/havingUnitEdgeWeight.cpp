// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<vector<int>> &, int );

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    
    vector<int> adj[N], dist(N, -1);
    for(int i = 0; i<M; i++){
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i: adj[node]){
            if(dist[i]==-1){
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
    return dist;
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin>>tc;

    while(tc--){
        int n, m, src;
        cin >> n >> m;
        vector<vector<int>> edges;
        graphInput(edges, m);
        cin>>src;
        vector<int> res = shortestPath(edges, n, m, src);
        for(auto it : res){
            cout<< it <<" ";
        }
        cout<<endl;
    }
    return 0;
}

void graphInput (vector<vector<int>> &edges, int m){
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v ;
        edges.push_back({u,v});
    }
}



