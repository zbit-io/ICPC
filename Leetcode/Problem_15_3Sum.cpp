#include<bits/stdc++.h>
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
class Solution1 {
    /**
    *@Time:2023-10-04 08:58:51
    *@Status:TLE 300/312
    *@Approach:双重循环+二分搜素+SET去重
    *@Complexity Analysis: 时间O(n^2 * log(n)) 空间O(n^2)
    *@Example usage:
    **/
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int> >ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target=0-nums[i]-nums[j];
                int p=binarysearch(nums,j+1,n-1,target);
                // cout<<target<<" p:"<<p<<endl;
                if(p!=-1){
                    //
                     ans.push_back(vector<int>{nums[i],nums[j],nums[p]});
                }
            }
        }
        set<vector<int> >temp(ans.begin(),ans.end());
        ans.assign(temp.begin(),temp.end());
        return ans;
    }
};
class Solution {
    /**
    *@Time:2023-10-04 08:58:51
    *@Status:TLE 300/312
    *@Approach:双重循环+二分搜索优化
    *@Complexity Analysis: 时间O(n^2 * log(n)) 空间O(n^2)
    *@Example usage:
    **/
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int> >ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
             if(nums[i]>0)break;
             if(i-1>=0&&nums[i]==nums[i-1])continue;
            // if(i>=n||nums[i]==nums[i+1])continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int target=0-nums[i]-nums[j];
                int p=binarysearch(nums,j+1,n-1,target);
                // cout<<target<<" p:"<<p<<endl;
                if(p!=-1){
                    //
                     ans.push_back(vector<int>{nums[i],nums[j],nums[p]});
                }
            }
        }
    
        return ans;
    }
};
int main() {
    vector<int>input{1,1,-2};
   vector<vector<int>> ans=Solution(). threeSum(input);
   for(const auto& i:ans){
    for(const auto& j:i){
        cout<<j<<' ';
    }
    cout<<'\n';
   }
    return 0;
}