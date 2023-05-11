// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

// You are given n(vertices), m(edges) and input in the form of 
// edges = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
// Find the number of ways (int) to reach from 0th node to n-1 th node in an UNDIRECTED WEIGHTED GRAPH

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<vector<int>> &, int );

int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int, int>> adj[n];
    for(auto it: roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    // for(int i = 0; i<n; i++){
    //     for(auto it: adj[i]){
    //         cout<<"("<<it.first<<","<<it.second<<") ";
    //     }
    //     cout<<endl;
    // }
    int src = 0;
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
    vector<int> ways(n, 0);
    vector<int> dist(n, -1);
    q.push({0, src});
    ways[src] = 1;
    dist[src] = 0;


    int mod = (int)(1e9 + 7);
    while(!q.empty()){
        int node = q.top().second; // name of the popped node
        int cost = q.top().first; // current distance of the src from the poppped node;
        q.pop();
        for(auto it: adj[node]){
            int adj_node = it.first; // name of the adj_node node
            int adj_node_cost = it.second; // path from node to adj_node
            if(dist[adj_node]==-1 || dist[node] + adj_node_cost < dist[adj_node]){
                ways[adj_node] = ways[node];
                dist[adj_node] = dist[node] + adj_node_cost;
                q.push({dist[adj_node], adj_node});
                // cout<<dist[adj_node] << " " << adj_node <<endl;
            }
            else if(dist[adj_node]==dist[node]+adj_node_cost){
                ways[adj_node] = (ways[adj_node] +  ways[node])%mod;
            }
        }
    }

    return ways[n-1]%mod;
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin>>tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> roads;
        graphInput(roads, m);
        int res = countPaths(n, roads);
        cout<<res<<endl;
    }
    return 0;
}

void graphInput (vector<vector<int>> &roads, int m){
    for(int i = 0; i<m; i++){
        int u, v, c;
        cin >> u >> v >> c ;
        roads.push_back({u,v,c});
    }
}