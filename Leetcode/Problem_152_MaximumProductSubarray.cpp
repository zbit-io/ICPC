#include<bits/stdc++.h>
using namespace std;
class Solution1 {
    /**
    *@Time:2023-09-10 10:10:27
    *@Status:WA
    *@Approach:Your current approach is trying to find a subarray with only positive numbers. However, the subarray with the largest product is not necessarily composed of only positive numbers. Consider the array [-2, -3, 4]. The largest product is 24 (from subarray [-2, -3, 4]), but none of its numbers are positive.
    *@Complexity Analysis:O(n)
    *@Example usage:
    **/
public:
    int maxProduct(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),max=-1e9,flag=true;
        while(i<n&&j<n){
            int t=1;
            while(j<n&&nums[j]>0){
                t=t*nums[j];
                j++;
                flag=false;
            }
            j=j+1;
            i=j;
            max=t>max?t:max;
        }
        if(flag)return 0;
        return max;
    }
};
class Solution2 {
public:
    /**
    *@Time:2023-09-10 10:11:59
    *@Status:AC
    *@Approach:遍历数组的每个元素，然后对于每个元素重新计算以该元素为结尾的所有子数组的乘积，并更新 maxProduct。如果任何时候 currentProduct 变为0，那么重置它为1
    *@Complexity Analysis:O(n^2)
    *@Example usage:
    **/
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int maxProduct = nums[0];
        for (int i = 0; i < n; i++) {
            int currentProduct = 1;
            for (int j = i; j < n; j++) {
                currentProduct *= nums[j];
                maxProduct = max(maxProduct, currentProduct);
            }
        }
        
        return maxProduct;
    }
};

class Solution {
public:
    /**
    *@Time:2023-09-10 11:55:12
    *@Status:AC
    *@Approach:动态规划
    *@Complexity Analysis:
    *@Example usage:
    **/
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>dpMax(n);
        vector<int>dpMin(n);
        int maxP=nums[0];
        dpMax[0]=nums[0];
        dpMin[0]=nums[0];
        if(n==1)return dpMax[0];
        for(int i=1;i<n;i++){
             if(nums[i]>=0){
                dpMax[i]=max(dpMax[i-1]*nums[i],nums[i]);
                dpMin[i]=min(nums[i],dpMin[i-1]*nums[i]);
                }
            else{
                dpMax[i]=max(nums[i],dpMin[i-1]*nums[i]);
                dpMin[i]=min(nums[i],dpMax[i-1]*nums[i]);
            }
            maxP=maxP>dpMax[i]?maxP:dpMax[i];
            
 
        }
        return maxP;
    }
};
int main() {
    vector<int>arr{-1,-2,-9,-6};//{-2,0,-1};//{2,3,-2,4};
  cout<< Solution().maxProduct(arr);
    return 0;
}