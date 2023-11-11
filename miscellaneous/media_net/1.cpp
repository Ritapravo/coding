#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
 
ll calculate_prefix(string &s) { 
    ll n= s.size();
    vector<int> pref(n);
    pref[0] = 0; 
   
    for(ll i = 1; i<n; i++){
        ll l = pref[i-1];
        while(l>0 && s[i]!=s[l])
            l = pref[l-1];
        if(s[i]==s[l])
            ++l;
        pref[i] = l;
        // cout<<pref[i]<<" ";
    }
    
    ll a = pref[n-1], b = n-a;
    if(a < b) return n;
    return a%b!=0 ? n : b;
} 
int solve(vector<string> &A) {
    ll l = 1,n=A.size();
    ll iterations[n];
    
    for(int i=0;i<n;i++){
        ll k = 1, pref = calculate_prefix(A[i]); 
        // cout<<endl<<pref;
        ll changes = 1;
        while(1){
            changes = (k*(k+1))/2; 
            if(changes%pref==0){
                iterations[i]=k;
                cout<<k<<" ";
                break;
            }
            k++;
        }
    }
    cout<<endl;
    ll ans=1;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n && iterations[i]!=1 ;j++){
            iterations[j] = iterations[j]/__gcd(iterations[j], iterations[i]);
        }
        ans = 1ll*(ans%mod*(iterations[i])%mod)%mod;
    }
    return ans%mod;
 return ans%mod;
}

void code(){
    int n;
    cin >> n;
    vector<string> A;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        A.push_back(s);
    }
    int res = solve(A);
    cout<<res<<endl;
}


int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input1.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t;
    cin >> t;
    while(t--)
        code();
    return 0;
}