#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<vector<int>> &, int );

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    for(auto it : edges){
        cout<< it[0] <<" "<<it[1]<<endl;
    }
    return vector<int>(N, 0);
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin>>tc;

    while(tc--){
        int n, m, src;
        cin >> n >> m;
        vector<vector<int>> edges;
        graphInput(edges, m);
        cin>>src;
        vector<int> res = shortestPath(edges, n, m, src);
        for(auto it : res){
            cout<< it <<" ";
        }
        cout<<endl;
    }
    return 0;
}

void graphInput (vector<vector<int>> &edges, int m){
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v ;
        edges.push_back({u,v});
    }
}

//g++ shortestPathDirectedGraphHavingUnitEdge.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/19_shortest_path_in_undirected_graph_having_unit_edge/shortestPathDirectedGraphHavingUnitEdge.cpp && ./a.out && rm ./a.out

