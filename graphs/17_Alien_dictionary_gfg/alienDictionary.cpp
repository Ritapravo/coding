// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include<bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    vector<int> inDegree(K, 0);
    for(int i = 0; i<N-1; i++){
        string s1 = dict[i], s2 = dict[i+1];
        int j = 0;
        while(j<s1.size() && j<s2.size()){
            if(s1[j]!=s2[j]){
                adj[int(s1[j]-'a')].push_back(int(s2[j]-'a'));
                inDegree[int(s2[j]-'a')]++;
                break;
            }
            j++;
        }
    }
    // for(auto it:adj){
    //     for(int i: it)
    //         cout<<i<<" ";
    //     cout<<endl;
    // }
    queue<int>q;
    for(int i = 0; i<K; i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    string ans = "";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans += char(node+int('a'));
        for(int i : adj[node]){
            inDegree[i]--;
            if(inDegree[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
}

int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int tc;
    cin>>tc;
    while(tc--){
        int n, k;
        cin >> n >>k;
        string dict[n];
        for(int i = 0; i<n; i++){
            cin>>dict[i];
        }
        string res = findOrder(dict, n, k);
        cout<<res<<endl;
    }
    return 0;
}
