#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        vector<int>ct(n);
        dp[0]=1;
        ct[0]=1;
        for(int i=1;i<n;i++){
            int k=0;
            bool noIncresing=true;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    noIncresing=false;
                    k=dp[j]>dp[k]?j:k;
                }
            }
            if(noIncresing){
                dp[i]=1;
                ct[i]=1;
            }
            else {
                int count=0;
                for(int j=0;j<i;j++){
                    if(nums[j]<nums[i]&&dp[j]==dp[k])count++;
                }
                dp[i]=dp[k]+1;
                ct[i]=count;
            }
        }

        int maxLength=0;
        for(auto i:dp){
            maxLength=max(maxLength,i);
        }
        int count=0;
        for(int i=0;i<n;i++){
            cout<<dp[i]<<' ';
            if(dp[i]==(maxLength-1==1?0:maxLength)count+=ct[i];
        }
        cout<<"\n count:";
        for(auto i:ct){
            cout<<i<<' ';
        }
        return count;
    }
};
int main() {
    vector<int>arr{2,2,2,2,2};
   cout<<Solution(). findNumberOfLIS(arr)<<'\n';
    return 0;
}