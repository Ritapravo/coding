#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<int> [], int );

vector<int> bfs (vector<int> adj[], int n, int start){
    int vis[n+1] = {0};
    vis[start] = 1;
    queue<int> q;
    q.push(start);
    vector <int> bfs_list;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs_list.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs_list;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    graphInput(adj, m);
    vector<int> res = bfs(adj, n, 1);
    print(res);
    return 0;
}

//g++ bfs.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/02_BFS/bfs.cpp && ./a.out && rm ./a.out

void print(v(int)&arr){
    cout<<"{";
    for(auto i=arr.begin(); i!=arr.end(); i++){
        cout<<*i;
        if(i!=arr.end()-1)
            cout<<",";
    }cout<<"}"<<endl;
}


void graphInput (vector<int> adj[], int m){
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}