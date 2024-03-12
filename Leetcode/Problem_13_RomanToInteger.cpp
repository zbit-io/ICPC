#include<bits/stdc++.h>
using namespace std;


class Solution {
    int dict[200];
public:
    Solution(){
        dict['I']=1;
        dict['V']=5;
        dict['X']=10;
        dict['L']=50;
        dict['C']=100;
        dict['D']=500;
        dict['M']=1000;
    }
    int romanToInt(string s) {
        int backNum=-1e9;
        int result=0;
        for(int i=s.size()-1;i>=0;i--){
            int currentNum=dict[s[i]];
            if(currentNum<backNum){
                result-=currentNum;
            }
            else{
                result+=currentNum;
            }
            backNum=currentNum;  
        }
        return result;
    }
};
int main() {
    cout<<Solution(). romanToInt("III");
    return 0;
}