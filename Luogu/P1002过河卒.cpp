#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>arr{3434,43,4,5,5,3,65,6,7,16};
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j-1>i;j--){
            if(arr[j-1]>arr[j]){
                int t=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=t;
            }
        }
    }
    for(auto i:arr)cout<<i<<" ";
    return 0;
}