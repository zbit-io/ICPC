#include<bits/stdc++.h>
using namespace std;
class Solution {
    /*做复杂了，因为没有考虑到如果出现了新的右指针不等于左指针，那么左指针的值必然不会再出现
    */
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=1,n=nums.size();
        if(n==0)return 0;
        if(n==1)return 1;
        // if(n==2&&nums[0]==nums[1])return 1;
        while(i<n&&nums[i-1]!=nums[i])i++;
        j=i;
        while(i<n&&j<n){
            while(j<n&&nums[j-1]==nums[j])j++;
            if(i<n&&j<n)nums[i++]=nums[j++];
        }
        return i;
    }
};
int main() {
    vector<int>a{1,1};//{0,0,1,1,1,2,2,3,3,4};
   cout<<Solution(). removeDuplicates(a)<<endl;
   for(auto i:a)cout<<i<<" ";
    return 0;
}