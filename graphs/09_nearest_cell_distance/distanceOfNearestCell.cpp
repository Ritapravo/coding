// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);



vector<vector<int>>nearest(vector<vector<int>>grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]==1){
                q.push({{i,j}, 0});
                visited[i][j] = 1;
            }
        }
    }
    int offset[5] = {-1,0,1,0,-1};
    while(!q.empty()){
        pair<int,int> node = q.front().first;
        int dist = q.front().second;
        grid[node.first][node.second] = dist;
        q.pop();
        for(int k = 0; k<4; k++){
            int x = node.first + offset[k];
            int y = node.second + offset[k+1];
            if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==0 && !visited[x][y]){
                visited[x][y] = 1;
                q.push({{x,y}, dist+1});
            }
        }
    }
    return grid;
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc;
    cin>>tc;
    while (tc--){
        int m, n;
        cin >>m >>n;
        vector<vector<int>> grid (m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cin>>grid[i][j];
            }
        }
        vector<vector<int>> res = nearest(grid);
        for(auto it: res){
            for (auto i : it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

//g++ distanceOfNearestCell.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/09_nearest_cell_distance/distanceOfNearestCell.cpp && ./a.out && rm ./a.out