#include<bits/stdc++.h>
using namespace std;
class Solution1 {
    /**
    *@Time:2023-09-21 11:41:49
    *@Status:TLE
    *@Approach:暴力
    *@Complexity Analysis:O(n^2)
    *@Example usage:
    **/
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            int fuel=gas[i];
            bool flag=false;
            for(int j=i;fuel-cost[j]>=0;j=(j+1)%n){
                if(flag&&j==i){
                    return i;
                }
                flag=true;
                fuel-=cost[j];
                fuel+=gas[(j+1)%n];
            }
        }
        return -1;
    }
};
class Solution {
    /**
    *@Time:2023-09-21 13:53:55
    *@Status:AC
    *@Approach:滑动窗口
    *@Complexity Analysis:
    *@Example usage:
    **/
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n=gas.size();
        if(n==1){
            return gas[0]-cost[0]>=0?0:-1;
        }
        for(int i=0;i<n;i++){
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }
        int i=0,j=0;
        while(i<gas.size()&&j<gas.size()){
            int fuel;
            do{
                fuel=gas[i]-cost[i];
                i++;
            } while(i<gas.size()&&fuel<0);
            j=i;
            int target=i-1+n;
            if(j>=gas.size())return -1;
           do{
                if(j==target){
                    return i-1;
                }
                fuel+=gas[j];
                fuel-=cost[j];
              
                j++;
           }while(j<gas.size()&&fuel>=0);
           i=j;
        }
        return -1;

    }
};

int main() {
    vector<int>gas{5,1,2,3,4},cost{4,4,1,5,1};
    cout<<Solution(). canCompleteCircuit(gas,cost);
    return 0;
}
