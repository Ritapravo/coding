// https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max (int a, int b){
    return a>b?a:b;
}

// using queue (inefficient method)
int MinimumEffort2(vector<vector<int>>& heights) {
    // for(auto it : heights){
    //     for (auto it2: it)
    //         cout<<it2<<" ";
    //     cout<<endl;
    // }
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> maxDiff(m, vector<int>(n, -1));
    queue <pair<int,int>> q;
    q.push({0,0});
    maxDiff[0][0] = 0;
    int offset[] = {-1,0,1,0,-1};
    while(!q.empty()){
        int node_x = q.front().first;
        int node_y = q.front().second;
        q.pop();
        for(int k = 0; k<4; k++){
            int x = node_x + offset[k];
            int y = node_y + offset[k+1];
            if(x>=0 && y>=0 && x<m && y<n && (maxDiff[x][y]==-1 || 
                (maxDiff[x][y]>max( maxDiff[node_x][node_y], abs(heights[node_x][node_y]-heights[x][y]) )) )){
                
                maxDiff[x][y] = max(maxDiff[node_x][node_y], abs(heights[node_x][node_y]-heights[x][y]));
                q.push({x,y});
            }

        }
    }

    return maxDiff[m-1][n-1];
}

// using priority queue (efficient method)
int MinimumEffort(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> maxDiff(m, vector<int>(n, -1));
    priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > q;
    q.push({0,{0,0}});
    maxDiff[0][0] = 0;
    int offset[] = {-1,0,1,0,-1};
    while(!q.empty()){
        int node_x = q.top().second.first;
        int node_y = q.top().second.second;
        q.pop();
        for(int k = 0; k<4; k++){
            int x = node_x + offset[k];
            int y = node_y + offset[k+1];
            if(x>=0 && y>=0 && x<m && y<n && (maxDiff[x][y]==-1 || 
                (maxDiff[x][y]>max( maxDiff[node_x][node_y], abs(heights[node_x][node_y]-heights[x][y]) )) )){
                
                maxDiff[x][y] = max(maxDiff[node_x][node_y], abs(heights[node_x][node_y]-heights[x][y]));
                q.push({maxDiff[x][y],{x,y}});
            }

        }
    }

    return maxDiff[m-1][n-1];
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin>>tc;
    while(tc--){
        int n, m;
        cin >> m >> n;
        vector<vector<int>> heights(m, vector<int>(n));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cin >> heights[i][j];
            }
        }
        int res = MinimumEffort(heights);
        cout<<res<<endl;
    }
    return 0;
}
