#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int backup=x;
        int t=0;
        if(x<0)return false;
        while(backup){
            t=t*10+backup%10;
            backup=backup/10;
        }
        if(t==x){
            return true;
        }
        return false;
    }
};
int main() {
   Solution().isPalindrome(123);
    return 0;
}