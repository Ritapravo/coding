#include <bits/stdc++.h>
using namespace std;

    int check(string s, int l, int r ){
        string t = s.substr(l, r-l+1);
        // cout<<t<<endl;
        int n = t.size(), i = 0, num = 0;
        while(i<n){
            num = num*2 + int(t[i]-'0');
            i++;
        }
        // cout<<num<<endl;
        int temp = log2(num)/log2(5);
        if(pow(5, temp)==num)
            return true;
        return false;
        
    }
    int solve(string s, vector<int> &dp, int i, int n){
        if(i>=n )
            return 0;
        if(check(s, i, n-1))
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        int m = INT_MAX;
        for(int k = i; k<n; k++){
            if(s[k]!='0' && (k==n-1 || s[k+1]!='0') && check(s, i, k)){
                int z = solve(s, dp, k+1, n);
                if(z!=INT_MAX)
                    m = min(m, 1+z);
            }
        }        
        return dp[i] = m;
    }
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        if(s[0]=='0')
            return -1;
        vector<int> dp(n+1, -1);
        int res = solve(s, dp, 0, n);
        if(res==INT_MAX)
            return -1;
        else 
            return res;
    }

int main() {
    vector<int> arr({14,30,29,49,3,23,44,21,26,52});
    string s = "111011100110101100101111101000011011";
    int n = s.size();
    // cout<<check(s, 0, n-1)<<endl;
    cout<<minimumBeautifulSubstrings(s)<<endl;
    return 0;
}