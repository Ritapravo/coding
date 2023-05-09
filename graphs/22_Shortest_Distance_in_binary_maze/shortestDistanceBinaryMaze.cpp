#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<int> [], int );

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout << grid[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<source.first<<" "<<source.second<<endl;
    cout<<destination.first<<" "<<destination.second<<endl;
    return 0;
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

