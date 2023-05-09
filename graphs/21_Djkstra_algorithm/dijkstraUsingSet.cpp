// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<vector<int>> [], int );

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    // for(int i = 0; i<V; i++){
    //     for(auto it: adj[i]){
    //         cout<<"("<<it[0]<<","<<it[1]<<") ";
    //     }
    //     cout<<endl;
    // }

    // syntax of a min heap;
    set< pair<int, int> > st;
    vector<int> dist(V, -1);
    st.insert({0,S});
    dist[S] = 0;

    while(!st.empty()){
        auto top = *(st.begin());
        int d = top.first;
        int node = top.second;
        st.erase(top);

        for(auto it: adj[node]){
            int adj_node = it[0], adj_node_dist = it[1];
            if(dist[adj_node]==-1 || dist[node] + adj_node_dist < dist[adj_node]){
                if(dist[adj_node]!=-1){
                    st.erase({dist[adj_node], adj_node});
                }
                dist[adj_node] = dist[node] + adj_node_dist;
                st.insert({dist[node] + adj_node_dist, adj_node});
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
        int V, E, S;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        graphInput(adj, E);
        cin >> S;
        vector<int> res = dijkstra(V, adj, S);
        for(auto it: res)
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}

void graphInput (vector<vector<int>> adj[], int m){
    for(int i = 0; i<m; i++){
        int u, v, c;
        cin >> u >> v >> c ;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
}