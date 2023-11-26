#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int dp[], vector<int> & nums, int start, int end){
        if(start>=end)
            return 0;
        if(dp[start]!=-1) return dp[start];
        int take = nums[start] + solve(dp, nums, start+2, end);
        int notTake = solve(dp, nums, start+1, end);
        return dp[start] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        int take = nums[0] + solve(dp, nums, 2, n-1);
        memset(dp, -1, sizeof(dp));
        int notTake = solve(dp, nums, 1, n);
        return max(take, notTake);
    }
};



