#include<iostream>
#include<vector>
using namespace std;
class Solution1 {
    vector<int>mem;
    int n;
public:
    int f(const vector<int>&cost,int i){
        if(i>=n)return 0;
        if(mem[i]!=-1)return mem[i];
        int c1=cost[i]+f(cost,i+1);
        int c2=cost[i]+f(cost,i+2);
        mem[i]=min(c1,c2);
        return mem[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
         n=cost.size();
        mem=vector<int>(n,-1);
        return min(f(cost,0),f(cost, 1));
    }
};
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,0);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<n;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        int s0=min(dp[n-1]+cost[n-1],dp[n-2]+cost[n-2]);

        return s0;
     
    }
};
int main() {
    return 0;
}