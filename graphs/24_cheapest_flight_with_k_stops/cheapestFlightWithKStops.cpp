#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<vector<int>> &, int );

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
    
    vector<pair<int, int>> adj[n];
    for(auto it: flights){
        adj[it[0]].push_back({it[1], it[2]});
    }
    // for(int i = 0; i<n; i++){
    //     for(auto it: adj[i]){
    //         cout<<"("<<it.first<<","<<it.second<<") ";
    //     }
    //     cout<<endl;
    // }

    vector<int> cost (n, -1);
    queue<pair<int, int>> q;
    q.push({src, 0});
    cost[src] = 0;
    int level = 0;
    int level_size = 1, temp_q_size = 1;

    while(!q.empty()){

        if(level_size==0){
            level_size = temp_q_size;
            level ++;
        }

        int node = q.front().first;
        int node_cost = q.front().second;
        q.pop();

        level_size--;
        temp_q_size--;
        
        // cout<<node<<" "<<node_cost<<" " <<level<< endl;
        if(level>K){
            break;
        }
        int c = 0;
        for(auto it : adj[node]){
            int child = it.first;
            int child_cost = it.second;
            if(cost[child]==-1 || node_cost+child_cost<cost[child]){
                cost[child] = node_cost+child_cost;
                q.push({child, cost[child]});
                temp_q_size++;
            }
        }
    
        // cout<<"level size = "<<level_size<<endl;
        
    }

    return cost[dst];
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin>>tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<vector<int>>flights;
        graphInput(flights, E);
        int src, dst, K;
        cin >> src >> dst >> K;
        int res = CheapestFLight(V, flights, src, dst, K);
        cout<<res<<endl;
    }
    return 0;
}

void graphInput (vector<vector<int>> &flights, int m){
    for(int i = 0; i<m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        flights.push_back({u,v,c});
    }
}