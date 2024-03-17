#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int dp(const vector<int>&nums,vector<int>&maxL,int i){
        if(maxL[i]!=-1)return maxL[i]; 
        int length=1;
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
            
                    length=max(dp(nums,maxL,j)+1,length);
            
            }
           
        }
        maxL[i]=length;
        return length;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>maxL(nums.size(),-1);
        int maxLength=0;
        for(int i=0;i<nums.size();i++){
            maxLength=max(maxLength,dp(nums,maxL,i));
        }
        return maxLength;
    }
};
int main() {
    vector<int> arr{10,9,2,5,3,7,101,18};
   Solution().lengthOfLIS(arr);
    return 0;
}