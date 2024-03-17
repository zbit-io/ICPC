#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
    int f(vector<int>&mem,int n){
        if(n<0)return 0;
        if(n==0){
            return 1;
        }
        if(mem[n]!=-1){
            return mem[n];
        }
        mem[n]=f(mem,n-1)+f(mem,n-2);
        return mem[n];
    }
public:
    int climbStairs(int n) {
        vector<int>mem(n+1,-1);
        return f(mem,n);
     
    }
};
class Solution {
public:
    int dp(int n){
        
    }
    int climbStairs(int n) {
        return dp(n);
    }
};
int main() {
   Solution().climbStairs(3);
    return 0;
}