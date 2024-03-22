#include<iostream>
#include<vector>
#include<stack>;
using namespace std;
class Solution {
    int n;
    vector<vector<int> >ans;
    void f(vector<int>&temp, stack<int>&nums){
        if(nums.empty()){
            ans.push_back(vector<int>(temp.begin(),temp.end()));
            return;
        }
        for(int i=p;p<n;i++){
            int t=nums.top();
            nums.pop();
            temp.push_back(t);
            f(temp,nums);
            temp.pop_back();
            nums.push(t);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int>temp;
        stack<int>s;
        for(auto i:nums){
            s.push(i);
        }
        f(temp,s);
        return ans;
    }
};
int main() {

   Solution(). 
    return 0;
}