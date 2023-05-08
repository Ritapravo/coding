#include <iostream>
#include <vector>

using namespace std;

void graphInput (vector<vector<int>> &adj, int m);

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin>>tc;

    while(tc--){
        int n, m, src;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        graphInput(adj, m);
        cin>>src;
    }
    return 0;
}

void graphInput (vector<vector<int>> &adj, int m){
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
