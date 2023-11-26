#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int n = costs.size(), l = -1, r = n, c = candidates;
        while(c-- && (++l)<n){
            pq1.push(costs[l]);
        }
        c = candidates;
        while(c-- && (--r)>l){
            pq2.push(costs[r]);
        }
        // cout<<n<<" "<<pq1.size()<<" "<<pq2.size()<<endl;
        long long res = 0, temp = 0, k_ = k;
        while(k_--){
            if((!pq1.empty()) && (!pq2.empty())){
                if(pq1.top()<=pq2.top()){
                    res += pq1.top();
                    pq1.pop();
                    if(l+1 < r)
                        pq1.push(costs[++l]);
                }
                else{
                    res += pq2.top();
                    pq2.pop();
                    if(r-1>l)
                        pq2.push(costs[--r]);
                }
                // cout<<"e ";
            }
            else if(!pq1.empty()){
                res += pq1.top();
                pq1.pop();
                cout<<res-temp<<" ";
            }
            else{
                res += pq2.top();
                pq2.pop();
            }
            temp = res;
            // cout<<k_<<" ";
        }
        return res;
    }
};