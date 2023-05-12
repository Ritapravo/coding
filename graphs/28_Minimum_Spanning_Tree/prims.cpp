// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        // decalring the min heap
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > q;
        vector<int> visited(V, 0);
        int src = 0;
        q.push({0, {src, -1}});
        int s = 0;
        vector<pair<int, int>> edges;
        while(!q.empty()){
            int c = q.top().first;
            int node = q.top().second.first;
            int parent = q.top().second.second;
            q.pop();
            if(visited[node]==1)continue;
            visited[node] = 1;
            s += c;
            if(!node==src)
                edges.push_back({parent, node});
            visited[node] = 1;
            for(auto it:  adj[node]){
                if(!visited[it[0]]){
                    q.push({it[1], {it[0], node}});
                }
            }
        }

        // for(auto it: edges){
        //     cout <<"("<<it.first<<","<<it.second<<") ";
        // }

        return s;
    }
};




int main()
{
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
