//https://practice.geeksforgeeks.org/problems/number-of-provinces/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<int> [], int );

void dfs (vector<vector<int>> &adj, int vis[], int node, int V){
    vis[node] = 1;
    for(int i = 0; i<V; i++){
        if(adj[node][i]==1 && i!=node){
            if(!vis[i]){
                vis[i] = 1;
                dfs(adj, vis, i, V);
            }
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    int vis[V] = {0};
    int res = 0;
    // cout<<endl;
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            res += 1;
            dfs(adj, vis, i, V);
        }
    }
    return res;
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> adj[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    int ans = numProvinces(adj, n);
    cout<<ans<<endl;
    return 0;
}


//g++ numberOfProvinces.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/04_number_of_provinces_gfg/numberOfProvinces.cpp && ./a.out && rm ./a.out