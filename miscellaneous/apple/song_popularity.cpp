#include<bits/stdc++.h>
using namespace std;


vector<int> getPopularOrder(vector<vector<int>> & arr){
    int n = arr.size(), m = arr[0].size();
    int dp[m][m];
    memset(dp, 0, sizeof(dp));
    // cout<<n<<" "<<m;
    for(int k = 0; k<n; k++){
        for(int i = 0; i<m-1; i++){
            for(int j = i+1; j<m; j++){
                dp[arr[k][i]][arr[k][j]] += 1;
            }
        }
    }
    vector<int> res(m);
    for(int i = 0; i<m; i++){
        int count = 0;
        for(int j =0; j<m; j++){
            if(i==j) continue;
            
            if(dp[i][j]>n/2){
                count++;
            }
            else if(dp[i][j]==n/2 && n%2==0 && i<j){
                count++;
            }
            

        }
        cout<<i<<" "<<count<<endl;
        res[m-count-1] = i;
    }


    return res;
}



void code(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> res = getPopularOrder(arr);
    // vector<int> res ({1, 2});
    for(auto it: res)
        cout<< it << " ";
    cout<< endl;
}


int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input1.txt";
    freopen("input1.txt", "r", stdin);

    int t; cin >> t;
    while(t--)
        code();
    return 0;
}