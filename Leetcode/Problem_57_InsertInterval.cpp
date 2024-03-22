#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0,j=0,n=intervals.size();
        vector<vector<int> >ans;
        vector<vector<int> >temp(intervals);
        temp.push_back(newInterval);
        sort(temp.begin(),temp.end());
        // bool flag=true;
        // for(int i=0;i<n;i++){
        //     if(flag&&newInterval[0]>intervals[i][0]&&newInterval[0]<intervals[i+1][0]){
        //         temp.push_back(newInterval);
        //         flag=false;
        //     }
        //     temp.push_back(intervals[i]);
        // }
        ans.push_back(temp[0]);
        for(int i=1;i<=n;i++){
            vector<int>&curr=temp[i];
            if(ans.back()[1]>=curr[0]){
                ans.back()[1]=max(ans.back()[1],curr[1]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
int main() {
//    Solution(). 
    return 0;
}