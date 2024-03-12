#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int>q(nums.begin(),nums.end());
        while(k--){
            int t=q.back();
            q.pop_back();
            q.push_front(t);
        }
        nums=vector<int>(q.begin(),q.end());
    }   
};
//额外的数组
//
int main() {
    vector<int>nums{-1,-100,3,99};
   Solution(). rotate(nums,2);
   for(auto i:nums){
    cout<<i<<' ';
   }
    return 0;
}