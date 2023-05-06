#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<int> [], int );




int numberOfEnclaves(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited (m ,vector<int>(n, 0));
    queue<pair<int, int>> q;

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j] == 1){
                q.push({i,j});
                visited[i][j] = 1;
            }
        }
    }
    
    int offset[] = {-1,0,1,0,-1};
    while(!q.empty()){
        int node_x = q.front().first, node_y = q.front().second;
        q.pop();
        for(int k = 0; k<4; k++){
            int x = node_x + offset[k];
            int y = node_y + offset[k+1];
            if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1 && !visited[x][y]){
                visited[x][y] = 1;
                q.push({x,y});
            }
        }
    }

    int res = 0;
    for(int i = 0; i<m; i++)
        for(int j = 0; j<n; j++)
            if(grid[i][j]==1 && !visited[i][j])
                res += 1;
        
    return res;
}

int main() {
    freopen("/home/ritapravo/Documents/coding/graphs/11_number_of_enclaves/input.txt", "r", stdin);
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
        int res = numberOfEnclaves(grid);
        cout<<res<<endl;
    }
    return 0;
}

//g++ numberOfEnclaves.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/11_number_of_enclaves/numberOfEnclaves.cpp && ./a.out && rm ./a.out

void bfs(vector<vector<int>>&grid, vector<vector<int>> &visited, int src_x, int src_y, int m, int n){
    visited[src_x][src_y] = 1;
    queue<pair<int, int>> q;
    q.push({src_x, src_y});
    int offset[] = {-1,0,1,0,-1};
    while(!q.empty()){
        int node_x = q.front().first, node_y = q.front().second;
        q.pop();
        for(int k = 0; k<4; k++){
            int x = node_x + offset[k];
            int y = node_y + offset[k+1];
            if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1 && !visited[x][y]){
                visited[x][y] = 1;
                q.push({x,y});
            }
        }
    }
}

int numberOfEnclaves2(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited (m ,vector<int>(n, 0));
    for(int j = 0; j<n; j++){
        if(grid[0][j]==1 && !visited[0][j]){
            if(grid[0][j]==1 && !visited[0][j]){
                bfs(grid, visited, 0, j, m, n);
            }
        }
        if(grid[m-1][j]==1 && !visited[m-1][j]){
            if(grid[m-1][j]==1 && !visited[m-1][j]){
                bfs(grid, visited, m-1, j, m, n);
            }
        }
    }
    for(int i = 1; i<m-1; i++){
        if(grid[i][0]==1 && !visited[i][0]){
            if(grid[i][0]==1 && !visited[i][0]){
                bfs(grid, visited, i, 0, m, n);
            }
        }
        if(grid[i][n-1]==1 && !visited[i][n-1]){
            if(grid[i][n-1]==1 && !visited[i][n-1]){
                bfs(grid, visited, i, n-1, m, n);
            }
        }
    }
    int res = 0;
    for(int i = 0; i<m; i++)
        for(int j = 0; j<n; j++)
            if(grid[i][j]==1 && !visited[i][j])
                res += 1;
        
    return res;
}