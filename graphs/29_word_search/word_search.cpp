#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(vector<vector<char>>& board,vector<vector<int>> &vis, int x, int y, int m, int n, int index, string &word ){
        index = index + 1;
        if(index>=word.size())
            return true;
        cout<<word[index-1]<<" ";
        vis[x][y] = 1;
        int offset[] = {-1,0,1,0,-1};
        bool res = 0;
        for(int k = 0; k<4; k++){
            int i = x+offset[k];
            int j = y+offset[k+1];
            if(i>=0 && j>=0 && i<m && j<n && !vis[i][j] && board[i][j]==word[index]){
                res = res || dfs(board, vis, i, j, m, n, index, word);
            }
        }
        vis[x][y] = 0;
        return res;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, vis, 0, 0, m, n, 0, word))
                        return true;
                }
            }
        }
        return false;
    }
};



void code(){
    int m, n;
    cin>>m>>n;
    string word;
    vector<vector<int>> board(m, vector<int>(n));
    cin>>word;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>board[i];
        }
    }
    Solution * sol = new Solution();
    cout<<sol->exist(board, word);
}


int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t;cin>>t;
    while(t--)
    code();
    return 0;
}
