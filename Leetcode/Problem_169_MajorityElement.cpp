#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>dict;
        for(auto i:nums){
            dict[i]++;
        }
        int max=dict.begin()->first;
        int times=dict.begin()->second;
        for(pair<int,int> i:dict){
           if(times<i.second){
            times=i.second;
            max=i.first;
           }
        }
        return max;
    }
};
class Solution {
public:
    /*分治算法*/
    int majorityElement(vector<int>& nums) {

    }
};

class Solution2 {
public:
/*Boyer-Moore 算法*/
    int majorityElement(vector<int>& nums) {

    }
};
int main() {
    vector<int>arr{2,2,1,1,1,2,2};
    cout<<Solution().majorityElement(arr);
    return 0;
}