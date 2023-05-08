// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// able to use this, since there is no cycle here. otherwise not possible using this algo
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<pair<int, int>> adj[], vector<int>&dist, int start){
    for(auto node: adj[start]){
        if(dist[node.first]==-1 || (dist[start] + node.second < dist[node.first])){
            dist[node.first] = dist[start] + node.second;
        }
        dfs(adj, dist, node.first);
    }
}

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    vector<pair<int,int>> adj[N];
    vector<int> dist(N, -1);
    for(auto edge: edges){
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    // for(int i = 0; i<N; i++){
    //     cout<<i<<" - ";
    //     for(auto it :adj[i]){
    //         cout<<"("<<it.first<< ","<<it.second<<") ";
    //     }
    //     cout<<endl;
    // }
    dist[0] = 0;
    dfs(adj, dist, 0);
    return dist;
}


int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
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

//g++ shortestPathInDAG.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/18_Shortest_path_in_DAG/shortestPathInDAG.cpp && ./a.out && rm ./a.out
