#include<bits/stdc++.h>
using namespace std;
int binarySearch(const vector<pair<int,int > >& arr,int i,int j,int target){
    while(i<=j){
        int mid=i+((j-i)>>1);
        // cout<<"mid:"<<mid<<" "<<arr[mid].first<<'\n';
        if(arr[mid].first>target){
            j=mid-1;
            continue;
        }
        if(arr[mid].first==target){
            return mid;
            continue;
        }
        if(arr[mid].first<target){
            i=mid+1;
            continue;
        }
    }
    return -1;
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        vector<pair<int,int> >temp;
        for(int i=0;i<n;i++){
            temp.push_back(make_pair(nums[i],i));
        }
        sort(temp.begin(),temp.end(),[](const pair<in t,int> &p1,const pair<int,int>& p2){
            return p1.first<p2.first;
        });
        for(int i=0;i<n;i++){
            int findRes=binarySearch(temp,i+1,n-1,target-temp[i].first);
            cout<<target-nums[i]<<" "<<i<<" "<<findRes<<'\n';
            if(findRes!=-1){
                 ans=vector<int>{temp[i].second,temp[findRes].second};
                return ans;
            }
        }
        return ans;
    }
};
int main() {
    auto nums=vector<int>{2222222,2222222};
    auto ans=Solution().twoSum(nums,4444444);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}