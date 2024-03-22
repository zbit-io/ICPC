#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int n;
    vector<vector<int> >ans;
    void f(int target,int p,vector<int>&temp,const vector<int>&nums){
        if(target<0||p==n)return;
        if(target==0){
            ans.push_back(vector<int>(temp.begin(),temp.end()));
            return;
        }
        for(int i=p;i<n;i++){
            temp.push_back(nums[i]);
            f(target-nums[i],p+1,temp,nums);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         n=candidates.size();
         vector<int>temp;
         f(target,0,temp,candidates);
         return ans;
    }
};
int main() {
    Solution(). 
    return 0;
}