#include<bits/stdc++.h>
using namespace std;
class Solution1 {
    /**
    *@Time:2023-09-21 09:31:24
    *@Status:AC
    *@Approach:题目所禁止的方法
    *@Complexity Analysis:O(n)
    *@Example usage:
    **/
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product=1;
        int count0=0;
        long long productWithoutZero=1;
        for(auto i:nums){
            product*=i;
            if(i!=0)productWithoutZero*=i;
            else count0++;
            if(count0>1)return vector<int>(nums.size(),0);
        }
        vector<int>ans;
        for(auto i:nums){
            int temp=i==0?productWithoutZero:product/i;
            ans.push_back(temp);
        }
        return ans;
    }
};
class Solution {
    /**
    *@Time:2023-09-21 09:30:58
    *@Status:AC
    *@Approach:前缀和
    *@Complexity Analysis:O(n)
    *@Example usage:
    **/
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>L,R,ans;
        L.push_back(1);
        int temp=1;
        for(auto i:nums){
            temp*=i;
            L.push_back(temp);
        }
        temp=1;

        for(int i=nums.size()-1;i>=0;i--){
            temp*=nums[i];
            R.push_back(temp);
        }
        R=vector<int>(R.rbegin()+1,R.rend());
        R.push_back(1);
        for(int i=0;i<nums.size();i++){
            int temp=L[i]*R[i];
            ans.push_back(temp);
            
        }
        return ans;
    }
};
int main() {
    vector<int> nums{1,2,3,4};
    nums=Solution().productExceptSelf(nums);
    for(auto i:nums)cout<<i<<" ";
    return 0;
}