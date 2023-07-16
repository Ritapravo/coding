#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr, int i, int n){
    int j = 2*i+1;
    int x = arr[i];
    while(j<n){
        if(j<n-1 && arr[j+1]>arr[j])j++;
        if(x>=arr[j])break;
        arr[i] = arr[j];
        arr[j] = x;
        i = j;
        j = 2*i+1;
    }
}
int deleteMax(vector<int>&arr, int &size){
    int x = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = x;
    size--;
    heapify(arr, 0, size);
    return x;
}
int findKthLargest(vector<int>& nums, int k) {
    int size = nums.size();
    for(int i = size/2-1; i>=0; i--)
        heapify(nums, i, size);
    int res;
    while(size)
        res = deleteMax(nums, size);
    for(int i: nums)
        cout<<i<<" ";
    cout<<endl;
    return res;
}



int main(){
    vector<int> nums ({3,2,1,5,6,4});
    int k = 2;
    cout<<findKthLargest(nums, k)<<endl;
    return 0;
}
