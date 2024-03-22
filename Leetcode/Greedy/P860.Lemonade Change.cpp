#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int>m;
    Solution():m(21,0){

    }
    bool lemonadeChange(vector<int>& bills) {
       
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                m[5]++;
            }
            else if(bills[i]==10){
                m[10]++;
                if(m[5]<=0)return false;
                m[5]--;
            }
            else if(bills[i]==20){
                m[20]++;
                if(m[10]>0&&m[5]>0){
                    m[10]--;
                    m[5]--;
                    continue;
                }
                if(m[5]>=3){
                    m[5]-=3;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};
int main() {
   Solution(). 
    return 0;
}