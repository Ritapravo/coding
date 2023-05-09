// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
    vector<vector<int>> adj[N+1];
    for(auto edge: edges){
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    // for(int i = 1; i<=N; i++){
    //     cout<<i<<" - ";
    //     for(auto it: adj[i]){
    //         cout<<"("<<it[0]<<","<<it[1]<<") ";
    //     }
    //     cout<<endl;
    // }
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    vector<int> dist(N+1, -1);
    vector<int> parent(N+1, -1);
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adj_node = it[0], adj_node_dist = it[1];
            if(dist[adj_node]==-1 || dist[node] + adj_node_dist < dist[adj_node]){
                dist[adj_node] = dist[node] + adj_node_dist;
                parent[adj_node] = node;
                pq.push({dist[node] + adj_node_dist, adj_node});
            }
        }
    }
    if(parent[N]==-1)return(vector<int>({-1}));
    vector<int> res;
    int k=N;
    while(k!=-1){
        res.push_back(k);
        k = parent[k];
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input2.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc;
    cin>>tc;
    while(tc--){
        int n, m;
        cin>>n >>m;
        vector<vector<int>> edges;
        for(int i = 0; i<m; i++){
            vector<int> temp;
            for(int j = 0; j<3; j++){
                int x; cin >>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        // for(auto it:  edges){
        //     for(auto i: it){
        //         cout << i <<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> res = shortestPath(n, m, edges);
        for(auto it: res)
            cout<<it<< " ";
        cout<<endl;
    }
    return 0;
}

