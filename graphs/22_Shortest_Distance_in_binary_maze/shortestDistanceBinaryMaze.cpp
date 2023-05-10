#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<int> [], int );

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    int m = grid.size(), n = grid[0].size();
    // for(int i = 0; i<m; i++){
    //     for(int j = 0; j<n; j++){
    //         cout << grid[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<source.first<<" "<<source.second<<endl;
    // cout<<destination.first<<" "<<destination.second<<endl;
    queue< pair<int, int> > q;
    vector<vector<int>> dist(m, vector<int>(n, -1));
    q.push(source);
    dist[source.first][source.second] = 0;

    int offset [] = {-1,0,1,0,-1};

    while(!q.empty()){
        int node_x = q.front().first;
        int node_y = q.front().second;
        q.pop();
        for(int k =0; k<4; k++){
            int x = node_x + offset[k];
            int y = node_y + offset[k+1];
            if(x>=0 && y>=0 && x<m && y<n && grid[x][y] == 1 && dist[x][y]==-1){
                dist[x][y] = dist[node_x][node_y] + 1;
                q.push({x, y});
            }
        }
    }

    // for(int i = 0; i<m; i++){
    //     for(int j = 0; j<n; j++){
    //         cout<<dist[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }

    return dist[destination.first][destination.second];
}


int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc; cin>>tc;
    while(tc--){
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int> (n));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cin >> grid[i][j];
            }
        }
        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        int res = shortestPath(grid, source, destination);
        cout<<res<<endl;
    }
    return 0;
}

