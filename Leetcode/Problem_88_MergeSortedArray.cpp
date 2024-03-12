#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m,j=0;i<nums1.size();i++,j++){
            nums1[i]=nums2[j];
        }
        sort(nums1.begin(),nums1.end());

    }
    
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp;
        int i=0,j=0;
        while(i<m||j<n){
            if(i<m&&j<n){
                temp.push_back(nums1[i]>nums2[j]?nums2[j++]:nums1[i++]);
            }
            if(i>=m){
               while(j<n){
                temp.push_back(nums2[j++]);
               }
            }
            if(j>=n){
                while(i<m){
                    temp.push_back(nums1[i++]);
                }
            }
        }
        nums1=temp;
    }
};
int main(){
     vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> b = {2, 5, 6};
    Solution().merge(a, 3, b, 3);
    for(auto i:a)cout<<i<<" ";
    
    return 0;
}
