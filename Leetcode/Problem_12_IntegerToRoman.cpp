#include<bits/stdc++.h>
using namespace std;
class Solution {
    map<int,string>dict;
    vector<int>arr{1000,900,500,400,100,90,50,40,10,9,5,4,1};
public:
    Solution(){
        dict = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
    };
    string intToRoman(int num) {
        string ans="";
        int i=0;
        while(i<arr.size()&&num>0){
            if(num-arr[i]>=0){
                num-=arr[i];
                ans+=dict[arr[i]];
            }else{
                i++;
            }
        }
        return ans;
    }
};
int main() {
   cout<<Solution(). intToRoman(3);
    return 0;
}