#include<iostream>
#include<bits/stdc++.h>
using namespace std;


signed main(){
    freopen("input1.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m;
    cin >> n >> m;
    int adj[n+1][n+1];
    memset(adj, 0, sizeof(adj));
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<n+1; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//g++ adjacencyMatrix.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/01_Graph_Representation/adjacencyMatrix.cpp && ./a.out && rm ./a.out