#include <algorithm>
#include<iostream>
#include <unordered_map>
#include <utility>
using namespace std;
class Solution1 {
public:

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int,int> > arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            arr.push_back(make_pair(nums[i], i));
        }
        sort(arr.begin(),arr.end(),[](pair<int,int> p1,pair<int,int> p2){
            if(p1.first==p2.first){
                return p1.second<p2.second;
            }
            return p1.first<p2.first;
        });
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n&&arr[j]==arr[i];j++){
                if(arr[i].first==arr[j].first&&abs(arr[i].second-arr[j].second)<=k){
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if()
        }

    }
};
int main() {
    
    return 0;
}