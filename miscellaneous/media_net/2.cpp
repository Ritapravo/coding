#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int z=0;

  int fun(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = n; j > 0; --j)
                dp[j] = min(dp[j], dp[max(j - time[i] - 1, z)] + cost[i]);
        return dp[n];
    }


void code(){
    int n;
    cin>>n;
    vector<int> time,cost;
    int s=0;
    for(int i=0;i<n;i++)
    {
        int k1,k2;
        cin>>k1>>k2;
        time.push_back(k1);
        cost.push_back(k2);
        s+=k2;
    }
    cout<<s-fun(cost,time)<<"\n";
}
signed main()
{
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input2.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t; cin >> t;
    while(t--)
        code();
    return 0;
}