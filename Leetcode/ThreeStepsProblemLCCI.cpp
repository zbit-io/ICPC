#include<bits/stdc++.h>
using namespace std;
class Solution1 {
    /**
    *@Time:2023-09-09 16:40:49
    *@Approach:TLE,递归解法
    *@Complexity Analysis:在该解决方案中，为了计算上台阶的方式个数，使用了递归的方式。递归函数f(t)会逐步减小t值，直到t小于等于0为止。每次递归调用会有3次更小的递归调用，因此递归树的层数为n。所以时间复杂度是O(3^n)。
    *@Example usage:
    **/
    int n,ans=0;
public:
    int waysToStep(int n) {
        this->n=n;
        f(n);
        return ans;
    }
    void f(int t){
        if(t<0)return;
        if(t==0){
            ans=(ans+1)%1000000007;
        }
        f(t-3);f(t-2);f(t-1);
    }
};
class Solution {
public:
    int waysToStep(int n) {
        vector<int>dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            if(i>=2)dp[i]=(dp[i]+dp[i-2])%1000000007;
            if(i>=3)dp[i]=(dp[i]+dp[i-3])%1000000007;
        }
        return dp[n];
    }
};
int main() {
   cout<<Solution().waysToStep(3);
    return 0;
}