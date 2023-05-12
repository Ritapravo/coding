// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    int E = edges.size();
    for(int i = 0; i<V-1 ; i++){
        for(int j = 0; j<E; j++){
            int u = edges[j][0], v = edges[j][1], c = edges[j][2];
            if(dist[u] != 1e8 && dist[u]+c < dist[v]){
                dist[v] = dist[u]+c;
            }
        }
    } 
    for(int j = 0; j<E; j++){
        int u = edges[j][0], v = edges[j][1], c = edges[j][2];
        if(dist[u] != 1e8 && dist[u]+c < dist[v]){
            return vector<int>(V, -1);
        }
    }
    return dist;
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        vector<int> res = bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}