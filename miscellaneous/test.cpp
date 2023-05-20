//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    int solve(vector<vector<int>>& points, vector<vector<int>>& dp, int ind, int k){
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        else if(ind==0){
            return dp[ind][k] = points[ind][k];
        }
        else{
            int m = 0;
            for(int i = 0; i<3; i++){
                if(i==k)continue;
                m = max(m,points[ind][k] + solve(points, dp, ind-1,i));
            }
            return dp[ind][k] = m;
        }
    }
        
    public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int a = solve(points, dp, n-1, 0);
        int b = solve(points, dp, n-1, 1);
        int c = solve(points, dp, n-1, 2);
        for(auto it: dp){
            for(auto i: it)
                cout<<i<<" ";
            cout<<endl;
        }
        cout<<endl<<a<<" "<<b<<" "<<c<<endl;
        return max(max(a,b),c);
    }
};

//{ Driver Code Starts.
int main() {
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends