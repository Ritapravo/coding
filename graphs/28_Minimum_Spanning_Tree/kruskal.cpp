// https://www.codingninjas.com/studio/problems/kruskal%E2%80%99s-minimum-spanning-tree-algorithm_1082553
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
	vector<int> rank, parent;
public:
	DisjointSet(int n){
		rank.resize(n+1, 0);
		parent.resize(n+1);
		for(int i = 0; i<=n; i++)
			parent[i] = i;
	}

	int findUPar(int node){
		if(parent[node]==node)
			return node;
		else 
			return parent[node] = findUPar(parent[node]);
	}

	void unionByRank(int u, int v){
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if(rank[ulp_u]==rank[ulp_v]){
			parent[ulp_u] = ulp_v;
			rank[ulp_u]++;
		}
		else if(rank[ulp_u]<rank[ulp_v]){
			parent[ulp_u] = ulp_v;
		}
		else{
			parent[ulp_v] = ulp_u;
		}
	}
};


bool cmp(vector<int>&a, vector<int>&b){
	return a[2]<b[2];
}
class Solution
{
	public:
    int spanningTree(int n, vector<vector<int>> &edges){
        sort(edges.begin(), edges.end(), cmp);
        DisjointSet ds(n);
        int minST = 0;
        for(auto it: edges){
            int u = it[0], v = it[1], w = it[2];
            if(ds.findUPar(u)!=ds.findUPar(v)){
                ds.unionByRank(u, v);
                minST += w;
            }
        }
        return minST;
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
        vector<vector<int>> edges;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u,v,w});
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, edges) << "\n";
    }

    return 0;
}
