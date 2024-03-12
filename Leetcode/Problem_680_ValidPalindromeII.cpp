#include<bits/stdc++.h>
using namespace std;
// bool isDeleted=false;
bool recursion(const string& s,int i,int j,bool isDeleted){

    if(i>=j)return true;
    if(s[i]==s[j]){
        return recursion(s,i+1,j-1,isDeleted);
    }
    else{
        if(isDeleted)return false;
        bool deleteL=recursion(s,i+1,j,true);
        if(deleteL)return true;
        bool deleteR=recursion(s,i,j-1,true);
        return deleteR;
    }

}
class Solution {
    /**
    *@Time:2023-09-30 10:32:00
    *@Status:AC
    *@Approach:贪心
    *@Complexity Analysis:时间/空间O（N）
    *@Example usage:
    **/
public:
    bool validPalindrome(string s) {
        return recursion(s,0,s.size()-1,false);
    }
};
int main() {
   cout<<Solution(). validPalindrome("abcca");
    return 0;
}