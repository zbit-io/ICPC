#include<iostream>
#include<vector>
using namespace std;
int binarysearch(const vector<int>&arr,int i,int j,int target){
    int  n=arr.size();
    while(i<=j){
        // int mid=(i+j)/2;
        int mid = i + ((j - i) >> 1);
        if(arr[mid]<target){
            i=mid+1;
            continue;
        }
        if(arr[mid]==target){
            return mid;
        }else{
            j=mid-1;
            continue;
        }
    }
    return -1;
}
int binarysearchrecursion(const vector<int>&arr,int i,int j, int target){
    if(i>j){
        return -1;
    }
    int mid=i+((j-i)>>1);
    if (arr[mid] < target) {
     return binarysearchrecursion(arr, mid+1, j, target);
      
    }
    if (arr[mid] == target) {
      return mid;
    } else {
      return binarysearchrecursion(arr, i, mid-1, target);
    }
}
int main() {
    
    return 0;
}