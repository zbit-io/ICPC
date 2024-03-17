#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int> >dp(n,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=1;
        for(int i=1;i<n;i++){
            
            if(nums1[i-1]<nums1[i]&&nums2[i-1]<nums2[i]){
                //case1
                if(nums1[i-1]<nums2[i]&&nums2[i-1]<nums1[i]){
                    dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
                    dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
                }
                //case2
                else{
                    dp[i][0]=dp[i-1][0];
                    dp[i][1]=dp[i-1][1]+1;
                }
            }
            else{
                dp[i][0]=dp[i-1][1];
                dp[i][1]=dp[i-1][0]+1;
            }
            }
            return min(dp[n-1][0],dp[n-1][1]);

    }
};

int main() {
    vector<int>nums1{1,3,5,4};
    vector<int>nums2{1,2,3,7};
    int ans=Solution().minSwap(nums1, nums2);
    cout<<ans;
    return 0;
}