#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*滑动窗口
        */
        int i=0,j=0,n=nums.size();
        if(n==0)return 0;
                while(i<n&&j<n){
                    while(i<n&&nums[i]!=val)i++;
                    j=i+1;
                    while(j<n&&nums[j]==val)j++;
                    if(i<n&&j<n){
                        nums[i]=nums[j];
                    nums[j]=val;   
                    }   
                }
      return i;  
    }
};
int main() {
    vector<int>a{0,1,2,2,3,0,4,2};
   cout<<Solution().removeElement(a,2)<<endl;
   for(auto i:a)cout<<i<<" ";
    return 0;
}