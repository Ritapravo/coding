#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<int> [], int );

void dfs(vector<int> adj[], vector<int> &dfs_path, int vis[], int start){
    vis[start] = 1;
    dfs_path.push_back(start);
    for(auto it: adj[start]){
        if(!vis[it]){
            dfs(adj,dfs_path, vis, it);
        }
    }
}

vector<int> dfs_start (vector<int>adj[], int n, int start){
    int vis[n+1] = {0};
    vector<int> dfs_path;
    dfs(adj, dfs_path, vis, start);
    return dfs_path;
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    graphInput(adj, m);
    vector<int> res = dfs_start(adj, n, 1);
    print(res);
    return 0;
}

//g++ dfs.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/03_DFS/dfs.cpp && ./a.out && rm ./a.out


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