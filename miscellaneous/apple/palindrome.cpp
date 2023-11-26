#include<bits/stdc++.h>
using namespace std;





class Solution {
private:
    int dp[1001][1001];
    int solve(string & s, int start, int end){
        if(start>end)
            return 0;
        if(start==end)
            return 1;
        if(dp[start][end]!=-1)
            return dp[start][end];
        if(s[start]==s[end]){
            return dp[start][end] =  2 + solve(s, start+1, end-1);
        }
        return dp[start][end] = max(solve(s, start+1, end), solve(s, start, end-1));
    }
public:
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        // return solve(s, 0, n-1);
        int ans = 0;
        for(int i = 0; i<n-1; i++){
            ans = max(ans, solve(s, 0, i) * solve(s, i+1, n-1));
        }
        return ans;
    }
};