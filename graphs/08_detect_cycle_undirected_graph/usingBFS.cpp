#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<int> [], int );


bool bfs(vector<int> adj[], vector<int> &visited, int start){
    queue<pair<int, int>> q;
    q.push({start,-1});
    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();
        for(int i: adj[node.first]){
            if(!visited[i] ){
                visited[i] = 1;
                q.push({i, node.first});
            }
            else if(i!=node.second){
                // cout<<"visited "<<node.first<<" "<<node.second<<" "<<i<<endl;
                return true;
            }
        }
    }
    return false;
}


bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited (V, 0);
    bool res = 0;
    for(int i = 0; i<V; i++){
        if(!visited[i]){
            visited[i] = 1;
            res = res || bfs(adj, visited, i); 
        }
    }
    return res;
}

int main() {
    freopen("/home/ritapravo/Documents/coding/graphs/08_detect_cycle_undirected_graph/input.txt", "r", stdin);
    int tc;
    cin>>tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int> adj[V+1];
        graphInput(adj, E);
        // for(auto it: adj){
        //     for(auto i: it)
        //         cout<<i<<" ";
        //     cout<<endl;
        // }
        cout << isCycle(V, adj)<<endl;
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

//g++ usingBFS.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/08_detect_cycle_undirected_graph/usingBFS.cpp && ./a.out && rm ./a.out