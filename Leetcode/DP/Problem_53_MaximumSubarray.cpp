#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();  
        vector<int>dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=min(dp[i-1],0)+nums[i];
        }
        int result;
        for(int i:dp){
            result=max(result,i);
        }
        return result;
    }
};
int main() {
   Solution(). 
    return 0;
}