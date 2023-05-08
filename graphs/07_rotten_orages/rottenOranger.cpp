// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int max_time = 0;
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]==2){
                visited[i][j] = 1;
                q.push({{i,j}, 0});
            }
        }
    }
    int offset[] = {-1,0,1,0,-1};
    while(!q.empty()){
        pair<pair<int, int>, int> node = q.front();
        q.pop();
        for(int k = 0; k<4; k++){
            int row = node.first.first + offset[k]; 
            int col = node.first.second + offset[k+1];
            if(row>=0 && col>=0 && row<m && col<n && grid[row][col]==1 && !visited[row][col]){
                visited[row][col] = 1;
                q.push({{row, col}, node.second +1});
                if(node.second + 1 > max_time)
                    max_time = node.second + 1;
            }
        }
    }
    for(int i = 0; i<m; i++)
        for(int j = 0; j<n; j++)
            if(grid[i][j] == 1 && !visited[i][j])
                return -1;

    return max_time;
}

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin >>tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(m, vector<int>(n, -1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){cin>>grid[i][j];}
        }
        int ans = orangesRotting(grid);
        cout<<ans<<endl;
    }
    return 0;
}

//g++ rottenOranger.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/07_rotten_orages/rottenOranger.cpp && ./a.out && rm ./a.out