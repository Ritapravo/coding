// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&grid, vector<vector<int>>&visited, vector<pair<int, int>> &vec, 
int i, int j, int start_x, int start_y, int m, int n){
    visited[i][j] = 1;
    vec.push_back({i-start_x, j-start_y});
    int offset[] = {-1,0,1,0,-1};
    for(int k = 0; k<4 ; k++){
        int x = i+offset[k];
        int y = j+offset[k+1];
        if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1 && !visited[x][y]){
            dfs(grid, visited, vec, x, y, start_x, start_y, m, n);
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    set<vector<pair<int, int>>> st;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]==1 && !visited[i][j]){
                vector<pair<int, int>> vec;
                dfs(grid, visited, vec, i, j, i, j, m, n);
                st.insert(vec);
            }
        }
    }
    // for(auto it1: st){
    //     for(auto it2: it1){
    //         cout << "(" << it2.first << "," <<it2.second << ") ";
    //     }
    //     cout<<endl;
    // }
    return st.size();
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc;
    cin>>tc;
    while(tc--){
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cin>>grid[i][j];
            }
        }
        int res = countDistinctIslands(grid);
        cout<<res<<endl;
    }
    return 0;
}