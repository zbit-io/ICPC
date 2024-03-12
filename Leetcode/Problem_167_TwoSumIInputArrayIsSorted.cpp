#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=0,n=numbers.size();
        vector<int>ans;
        while(i<n){
            j=i+1;
           // cout<<i<<" "<<j<<'\n';
            while(j<n){
                if(numbers[i]+numbers[j]>target)break;
                if(numbers[i]+numbers[j]==target){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    return ans;
                }
                j++;
            }
            bool flag=true;
            while(i+1<n&&numbers[i]==numbers[i+1]){//跳过恶意样例
                i++;
                flag=false;
            }
            if(flag)i++;
        
        }
        return ans;
    }
};
  int binarySearch(int i,int j,int target,const vector<int>&arr){
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid]<target){
                i=mid+1;
                continue;
            }
            if(arr[mid]>target){
                j=mid-1;
                continue;
            }
        }
        return -1;
    }
class Solution {
    /**
    *@Time:2023-09-28 10:04:39
    *@Status:AC
    *@Approach:二分搜索
    *@Complexity Analysis:O(n*logn)
    *@Example usage:
    **/
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int sn=target-numbers[i];
            int t=binarySearch(i+1,n-1,sn,numbers);
            if(t!=-1){
                ans.push_back(i+1);
                ans.push_back(t+1);
                return ans;
            }

        }
        return ans;
    }
};
int main() {
    vector<int>nums{2,3,4};
    int target=6;
    vector<int>ans=Solution().twoSum(nums,target);
    for(auto i:ans){
        cout<<i<<" ";
        
    }
    // cout<<binarySearch(3,nums.size()-1,25,nums);
    return 0;
}

