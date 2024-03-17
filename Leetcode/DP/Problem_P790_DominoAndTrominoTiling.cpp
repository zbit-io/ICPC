#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    long numTilings(long n) {
        vector<vector<long> >dp(n+1,vector<long>(3,0));
        dp[1][0]=1;
        dp[1][1]=0;
        dp[1][2]=1;
        for(long i=2;i<=n;i++){
            dp[i][0]=dp[i-1][2];
            dp[i][1]=(dp[i-1][1]+2*dp[i-1][0 ])%(1000000007);
            dp[i][2]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%(1000000007);
        }
        return  dp[n][2];
    }
};
int main() {
    cout<< Solution(). numTilings(3);
    return 0;
}