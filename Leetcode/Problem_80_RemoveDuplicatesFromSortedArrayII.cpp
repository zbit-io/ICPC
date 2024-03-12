#include<bits/stdc++.h>
using namespace std;
class Solution {
    
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,t=1,n=nums.size();
        while(i<n&&j<n){
            t=1;
            while(j+1<n&&nums[j]==nums[j+1]){
                t++;
                j++;
            }
            t=t<=2?t:2;
            while(t--){
                if(i<n&&j<n)nums[i++]=nums[j];
            }
            j++;
        }
        return i;
    }
};
int main() {
    vector<int>a{0,0,1,1,1,1,2,3,3};//{1,1,1,2,2,3};//{0,0,1,1,1,2,2,3,3,4};
   cout<<Solution(). removeDuplicates(a)<<endl;
   for(auto i:a)cout<<i<<" ";
    return 0;
}