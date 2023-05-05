#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<int> [], int );

void search(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &visited, int m, int n){
    // cout<<"i="<<i<<" j="<<j<<endl;
    visited[i][j] = 1;
    for (int delRow = -1; delRow<=1; delRow++){
        for(int delCol=-1; delCol <=1; delCol++){
            int row = i+delRow;
            int col = j+delCol;
            if(row>=0 && col>=0 && row<m && col<n && grid[row][col]=='1' && !visited[row][col])
                search(grid, row, col, visited, m, n );
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited (m, vector<int>(n, 0));
    int res = 0;
    for (int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                res += 1;
                search(grid, i, j, visited, m, n);
            }   
        }
    }
    return res;
}

int main() {
    freopen("/home/ritapravo/Documents/coding/graphs/05_number_of_islands_gfg/input.txt", "r", stdin);
    int n, m;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n, '#'));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){cin>>grid[i][j];}
    }
    int ans = numIslands(grid);
    cout<<ans<<endl;
    return 0;
}

//g++ numberOfIslands.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/05_number_of_islands_gfg/numberOfIslands.cpp && ./a.out && rm ./a.out