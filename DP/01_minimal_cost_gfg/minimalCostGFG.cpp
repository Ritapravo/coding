// https://practice.geeksforgeeks.org/problems/minimal-cost/1

// redundant use od 2d dp. Can be done using 1d dp
#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
        int solve(vector<int> & height, vector<vector<int>> &dp, int n, int k){
            if(n==0)
                return dp[n][k] = 0;
            // else if(k==1)
            else if(dp[n][k]!=-1)
                return dp[n][k];
            else {
                int m = INT_MAX;
                for(int i = 1; i<=k && i<=n; i++)
                    m = min(m, abs(height[n]-height[n-i])+solve(height, dp, n-i, k));
                return dp[n][k] = m;
            }
        }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        int res = solve(height, dp, n-1, k);
        for(auto it: dp){
            for(auto i: it)
                cout<<i<<" ";
            cout<<endl;
        }
        return res;
    }
};

int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}