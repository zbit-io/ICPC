#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
    map<char,string> dict;
    Solution(){
        dict['2']="abc";
        dict['3']="def";
        dict['4']="ghi";
        dict['5']="jkl";
        dict['6']="mno";
        dict['7']="pqrs";
        dict['8']="tuv";
        dict['9']="wxyz";
    }
    string d;
    vector<string> ans;
public:
    void f(int p,string t){
        if(p==d.size()){
            ans.push_back(t);
            return;
        }
        string dt=dict[d[p]];
        for(int i=0;i<dt.size();i++){
            f(p+1,t+dt[i]);
        }

    }
    vector<string> letterCombinations(string digits) {
        f(0,digits);
        return ans;
    }
};
int main() {
   Solution(). 
    return 0;
}