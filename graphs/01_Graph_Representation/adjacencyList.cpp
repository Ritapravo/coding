#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>


void print(v(int)&arr){
    cout<<"{";
    for(auto i=arr.begin(); i!=arr.end(); i++){
        cout<<*i;
        if(i!=arr.end()-1)
            cout<<",";
    }cout<<"}"<<endl;
}


signed main(){
    freopen("input2.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1]; // array of vectors
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i<n+1; i++){
        print(adj[i]);
    }
    return 0;
}


//g++ adjacencyList.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/01_Graph_Representation/adjacencyList.cpp && ./a.out && rm ./a.out