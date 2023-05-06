// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
// look for better solution. This is taking more space complexity
// better idea to do bfs only from the edges and mark all nodes connected to the edges with 1
// traverse through the entire grid. If 'O' found and not visited, mark it as 'X'
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v(a) vector<a>
void print(v(int)&);
void graphInput (vector<int> [], int );

void bfs(vector<vector<char>> &mat, vector<vector<int>> &visited, int x, int y, int m, int n){
    queue<pair<int, int>> q;
    q.push({x, y});
    vector<pair<int, int>> temp;
    int offset[] = {-1,0,1,0,-1};
    bool isSurrounded = true;
    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();
        if((node.first==0 || node.second==0 || node.first==m-1 || node.second==n-1)){
            // cout<<"margin "<<node.first<<" "<<node.second<<endl;
            isSurrounded = false;
        }
        else temp.push_back({node.first, node.second});
        for(int k = 0; k<4; k++){
            int x_temp = node.first + offset[k];
            int y_temp = node.second+ offset[k+1];
            if(x_temp>=0 && y_temp>=0 && x_temp<m && y_temp<n && mat[x_temp][y_temp]=='O' && !visited[x_temp][y_temp]){  
                // cout<<"temp "<<x_temp<<" "<<y_temp<<endl;
                visited[x_temp][y_temp] = 1;
                q.push({x_temp, y_temp});
            }
            
        }
    }
    if(!isSurrounded) return;
    for(auto it : temp){
        // cout<<it.first<<" "<<it.second<<endl;
        mat[it.first][it.second] = 'X';
    }
}

vector<vector<char>> fill(int m, int n, vector<vector<char>> mat)
{
    // int m = mat.size(), n = mat[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(!visited[i][j] && mat[i][j]=='O'){
                visited[i][j] = 1;
                bfs(mat, visited, i, j, m, n);
            }
        }
    }
    return mat;
}

int main() {
    freopen("/home/ritapravo/Documents/coding/graphs/10_replace_O_with_X/input.txt", "r", stdin);
    int tc;
    cin>>tc;
    while(tc--){
        int m, n;
        cin >> m >> n;
        vector<vector<char>> mat(m, vector<char>(n, '#'));
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cin>>mat[i][j];
            }
        }
        vector<vector<char>> res = fill(m, n, mat);
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

//g++ replaceOwithX.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/10_replace_O_with_X/replaceOwithX.cpp && ./a.out && rm ./a.out