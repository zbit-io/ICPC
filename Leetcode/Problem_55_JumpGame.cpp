#include<bits/stdc++.h>
using namespace std;
class Solution1 {
    /**
    *@Time:2023-09-11 17:28:12
    *@Status:TLE
    *@Approach:DFS
    *@Complexity Analysis:
    *@Example usage:
    **/
    bool can=false;
public:
    bool canJump(vector<int>& nums) {
        f(0,nums);
        return can;
    }
    void f(int now,const vector<int>&nums){
        int n=nums.size();
        if(now>=n)return;
        if(now==n-1){
            can=true;
            return;
        }
        int maxStep=nums[now];
        for(int i=maxStep;!can&&i>0;i--){
            f(now+i,nums);
        }
    }
};
class Solution2 {
    /**
    *@Time:2023-09-11 20:00:04
    *@Status:AC
    *@Approach:DFS+剪枝+记忆化搜索
    *@Complexity Analysis:
    *@Example usage:
    **/
public:
    bool canJump(vector<int>& nums) {
        vector<short>canJump(nums.size(),-1);
        return f(0,nums,canJump);
    }
    bool f(int now,const vector<int>&nums,vector<short>&canJump){
        int n=nums.size();
        if(now>=n)return false;
        if(now==n-1){
            return true;
        }
        int maxStep=nums[now];
        bool flag=false;
        for(int i=maxStep;i>0;i--){
            if(i+now>=n)continue;
            if(canJump[now+i]!=-1)return canJump[i+now];
            else {
                bool t= f(now+i,nums,canJump);
                canJump[now]=canJump[now]==1?1:t;
                canJump[now+i]=t;
                if(t)return true;
            }
        }
        return false;
    }
};
class Solution {
    /**
    *@Time:2023-09-11 20:04:00
    *@Status:
    *@Approach:DP
    *@Complexity Analysis:
    *@Example usage:
    **/
public:
    bool canJump(vector<int>& nums) {
         int n=nums.size()-1;
        if(n==0)return true;
        vector<bool>dp(n,false);
        dp[n]=true;
        for(int i=n-1;i>=0;i--){
            if(dp[i+1]){
                dp[i]=nums[i]>=1;
            }else{
                dp[i]=nums[i]+i>=n?true:false;
            }
            if(dp[i])n=i;
        }
           return dp[0];
    }
 
};
int main() {
    vector<int>nums{2,3,1,1,4};
    
   cout<<Solution().canJump(nums);
    return 0;
}