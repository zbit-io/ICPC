#include <algorithm>
#include <functional>
#include<iostream>
#include <iterator>
#include <queue>
#include<vector>
using namespace std;
extern int aaabb;
class Attemp1 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        
        
        priority_queue<vector<int>,vector<vector<int> >,greater<vector<int> > >pq;
        for(auto p:points){
            pq.push(p);
        }
        int ans=0;
        while(pq.size()>=2){
            vector<int>p1=pq.top();
            pq.pop();
            vector<int>p2=pq.top();
            pq.pop();
            if(p1[1]>=p2[0]){
                pq.push(vector<int>{p2[0],min(p1[1],p2[1])});
                continue;
            }
            ans+=2;
        }
        if(!pq.empty())ans++;
    
        return ans;
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int> &p1,vector<int> &p2){
            return p1[1]<p2[1];
        });
        int n=points.size();
        int ans=0;
        vector<int>isBoom(n,false);
        for(int i=0;i<n;i++){
            if(isBoom[i])continue;
            int p=points[i][1];
            ans++;
            for(int j=0;j<n;j++){
                if(points[j][0]<p&&points[j][1]>p){
                    isBoom[j]=true;
                }
            }
        }
        return ans;
    }
};
int main() {
    // cout<<aaabb;
    return 0;
}