#include<iostream>
#include <string>
#include<vector>
using namespace std;
class Solution1 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        vector<string>ans;
        while(j<n){
            if(j+1<n&&nums[j+1]==nums[j]+1){
                j++;
                continue;
            }
            if(nums[j]!=nums[i])ans.push_back(to_string(i)+"->"+to_string(j));
            else ans.push_back(to_string(nums[i]));
            i=j+1;
            
        }
        return ans;
    }
};
int main() {
//    Solution(). 
    return 0;
}