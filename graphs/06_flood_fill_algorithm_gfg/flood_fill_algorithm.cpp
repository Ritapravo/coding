//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& image, vector<vector<int>>& visited, int i, int j, int m, int n, int newColor){
    visited[i][j] = 1;
    int offset[5] = {-1, 0, 1, 0, -1};
    for(int k = 0; k<4; k++){
        int row = i+offset[k];
        int col = j+offset[k+1];
        if(row>=0 && col>=0 && row<m && col<n && image[i][j]==image[row][col] && !visited[row][col])
            dfs(image, visited, row, col, m, n, newColor);
    }
    image[i][j] = newColor;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size(), n = image[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    dfs(image,visited, sr, sc, m, n, newColor);
    return image;
}

int main(){
    freopen("/home/ritapravo/Documents/coding/graphs/06_flood_fill_algorithm_gfg/input.txt", "r", stdin);
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
        cout<<endl;
	}
	return 0;
}
//g++ flood_fill_algorithm.cpp && ./a.out && rm ./a.out
//g++ ~/Documents/coding/graphs/06_flood_fill_algorithm_gfg/flood_fill_algorithm.cpp && ./a.out && rm ./a.out