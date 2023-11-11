#include<bits/stdc++.h>
using namespace std;
int n,m,k1,k2;
const double eps=1e-9;

double fun(int mid)
{
	double v1=(double)((double)n-(double)k1*mid)/k2;
	double v2=(double)((double)m-(double)k2*mid)/k1;
	if(v1<0||v2<0)return -1;
	if(v1>v2)return v2+mid;
	return v1+mid;
}
void code()
{
	
	cin>>n>>m>>k1>>k2;
	int low=0;int high=min(n/k1,m/k2);
	int val=high;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		double z=fun(mid);
		double z1=fun(mid+1);
		// cout<<mid<<" "<<z<<" "<<z1<<"\n";
		if(z>z1)
		{
			val=z;
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	cout<<val<<"\n";
}

int main(){
    string filePath(__FILE__);
    string inputPath = filePath.substr(0, filePath.find_last_of("//"))+"/input1.txt";
    freopen(inputPath.c_str(), "r", stdin);
    int t; cin >> t;
    while(t--){
        code();
    }
}