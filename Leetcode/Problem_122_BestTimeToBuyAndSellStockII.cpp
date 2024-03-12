#include<bits/stdc++.h>
using namespace std;
class Solution1 {
    /**
    *@Time:2023-09-10 12:17:04
    *@Status:
    *@Approach:贪心
    *@Complexity Analysis:
    *@Example usage:
    **/
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-prices[i-1]>0)maxP+=(prices[i]-prices[i-1]);
        }
        return maxP;
    }
};
class Solution {
    /**
    *@Time:2023-09-11 16:26:16
    *@Status:AC
    *@Approach:这段代码是一个解决股票买卖问题的函数。给定一个数组prices，表示每天的股票价格，函数返回最大的利润。

代码中定义了一个Solution类，其中有一个成员函数maxProfit。该函数接受一个vector类型的参数prices，表示每天的股票价格。函数内部使用动态规划算法求解最大利润。

在函数内部，首先通过prices.size()获取数组的长度n。然后定义一个二维数组dp，用来保存每天持有或不持有股票的最大利润。

初始化dp[0][0]=0表示第一天不持有股票的利润为0，dp[0][1]=-prices[0]表示第一天持有股票的利润为-prices[0]（买入了股票）。

然后使用循环遍历1到n-1的每一天，根据状态转移方程更新dp数组。dp[i][0]表示第i天不持有股票的最大利润，可以选择前一天不持有股票的利润dp[i-1][0]，或者前一天持有股票的利润加上第i天的股票价格dp[i-1][1]+prices[i]中的较大值。

dp[i][1]表示第i天持有股票的最大利润，可以选择前一天不持有股票的利润减去第i天的股票价格dp[i-1][0]-prices[i]，或者选择前一天持有股票的利润dp[i-1][1]中的较大值。

最后函数返回dp[n-1][0]，即最后一天不持有股票的最大利润。
    *
    *@Complexity Analysis:O(n)
    *@Example usage:
    **/
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int> >dp(n,vector<int>(2));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
        }
        return dp[n-1][0];
    }
};
int main() {
    vector<int>prices{7,1,5,3,6,4};
   cout<<Solution(). maxProfit(prices);
    return 0;
}