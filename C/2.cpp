#include<bits/stdc++.h>
using namespace std;

string f(pair<int, pair<int, int>> p){
    int a = p.first, b = p.second.first, c = p.second.second;
    return to_string(a)+" "+to_string(b)+" "+to_string(c);
}

int solve(vector<vector<int>>& grid, int jx, int jy) {
    int maxlen = 0, m = grid.size(), n = grid[0].size();
    unordered_map<int, int> mp;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]==2){
                mp[i*10+j] = maxlen++;
            }
        }
    }
    // cout<<"total chese "<<maxlen<<endl;
    queue<pair<int,pair<int, int>>> q;
    unordered_set<string> vis;
    int tmask  = 0; 
    if(grid[0][0]==2)
        tmask = 1;
    q.push({tmask, {0,0}});
    vis.insert(f({tmask, {0,0}}));
    int step = 0, offset[]={-1,0,1,0,-1};
    while(!q.empty()){
        int q_size = q.size();
        while(q_size--){
            auto t = q.front();
            int mask = t.first;
            int x = t.second.first, y = t.second.second;
            q.pop();
            if(mask == (1<<maxlen)-1 && x==jx && y==jy)
                return step;
            for(int k = 0; k<4; k++){
                int i = x+offset[k];
                int j = y+offset[k+1];
                int keys = mask;
                if(i>=0 && j>=0 && i<m && j<n){
                    int c = grid[i][j];
                    if(c==1) continue;
                    if(c==2){
                        keys = keys | (1<<(mp[i*10+j]));
                    }
                    if(!vis.count(f({keys, {i, j}}))){
                        vis.insert(f({keys, {i, j}}));
                        q.push({keys,{i,j}});
                    }
                }
            }
            

        }
        step++;
    }
    return -1;
}


int main()
{
    vector<vector<int>> v;
    int x , y;
    // v = {{0,2,0}, {0,0,1}, {1,1,1}};
    // x = 1; y = 1;
    // v = {{0,2,0}, {1,1,2}, {1,0,0}};
    // x = 2; y = 1;
    // v = {{0,1,0}, {1,0,1}, {0,2,2}};
    // x = 1; y = 1;
    // v = {{2,0,0}, {0,0,1}, {1,1,1}};
    // x = 1; y = 1;
    v = {{2,1,0}, {0,0,1}, {2,0,2}};
    x = 1; y = 0;

    cout << solve(v, x, y)<<endl;
 
 
    return 0;
}