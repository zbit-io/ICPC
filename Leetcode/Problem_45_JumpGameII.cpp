#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    int jump(vector<int>& nums) {

    }
};

class BadSolution1 {
   /**
   *@Time:2023-09-13 16:02:28
   *@Status:WA 81/120
   *@Approach:您的代码试图为每个位置找到到达数组末尾所需的最小跳数。但问题是，通过简单地为每个位置找出最小的跳数，我们可能并不总是得到从当前位置到数组末尾的最优解。因为从某个位置可能需要更少的跳数到达末尾，但这不意味着从当前位置到该位置加上从该位置到末尾的跳数是最优的。
   *@Complexity Analysis:
   *@Example usage:
   **/
    const int INF=1e9;
     int minTimes=INF;
public:
    int jump(vector<int>& nums) {
        vector<int>canJump(nums.size(),INF);
        f(0,nums,canJump,0);
        return minTimes;
    }
    int f(int now,const vector<int>&nums,vector<int>&canJump,int jumpTimes){
        int n=nums.size();
       if(now>=n)return INF;
       if(now==n-1){
        minTimes=minTimes<jumpTimes?minTimes:jumpTimes;
        return jumpTimes;
       }
       for(int i=nums[now];i>0;i--){
            int t=now+i<n&&canJump[now+i]!=INF?canJump[now+i]:f(now+i,nums,canJump,jumpTimes+1);
            canJump[now]=t+1;
    
       }
       return canJump[now];
    }
};
class BadSolution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumpTimes=0;
        if(n==1)return 0;
        //  if(n==2)return 1;
        for(int i=0;i<n;i++){
            int nextJump=1;
            for(int j=1;i+j<n&&j<=nums[i];j++){
                nextJump=nums[i+j]>nums[i+nextJump]?j:nextJump;
                
            }
            i+=nextJump;
            jumpTimes++;
        }
        return jumpTimes;
    }
};
class Solution1 {
    /**
    *@Time:2023-09-14 09:15:22
    *@Status:AC
    *@Approach:贪心
    *@Complexity Analysis:O(n)
    *@Example usage:
    **/
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumpTimes = 0;
        int currentEnd = 0, farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            // 使用当前位置总是尝试扩展我们可以到达的最远位置。
            farthest = max(farthest, i + nums[i]);

            // 如果我们已经到达了当前“跳跃范围”的末尾，就增加跳跃次数
            if (i == currentEnd) {
                jumpTimes++;
                currentEnd = farthest;
            }
        }
        return jumpTimes;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        动态规划
    }
};
int main() {
    vector<int>nums{1,2,3};
   cout<<Solution().jump(nums);
    return 0;
}