// https://www.codingninjas.com/studio/problems/travelling-salesman-problem_1385180
#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

int solve(vector<vector<int>>&dp,vector<vector<int>> &dist, int n, int root, int start, int mask){
	if(mask==0)
		return dist[start][root];
	if(dp[start][mask]!=-1)
		return dp[start][mask];
	int ans = INT_MAX;
	for(int i = 0; i<n; i++){
		if(mask&(1<<i)){
			ans = min(ans, dist[start][i]+solve(dp, dist, n,root, i, mask^(1<<i)));
		}
	}
	return dp[start][mask] = ans;
}

int shortestRoute(vector<vector<int>> &distance)
{
	int n = distance.size();
	int mask = (1<<n)-1;
	vector<vector<int>> dp(n+1, vector<int>(mask+1, -1));
	int root = 0; // root(the point of start and return) can be any number 
	// from 0 to n-1, for convenience we can chose root as 0
	return solve(dp,distance, n, root, root, mask^(1<<root));
}

void code(){
    int n;
    cin>>n;
    vector<vector<int>> distance(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>distance[i][j];
        }
    }
    cout<<shortestRoute(distance)<<endl;
}


int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t; cin>>t;
    while(t--)
    code();
    return 0;
}
