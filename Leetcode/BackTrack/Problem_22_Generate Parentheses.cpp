#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
    vector<string>all;
public:
    void f(int a,int b,string s){
        if(a==0&&b==0){
            all.push_back(s);
            return;
        }
        if(a>0)f(a-1,b,s+'(');
        if(b>0)f(a,b-1,s+')');
    }
    bool check(string s){
        stack<char> bl;
        for(char c:s){
            if(c=='('){
                bl.push(c);
            }
            else{
                if(bl.empty())return false;
                bl.pop();
            }
        }
        return bl.empty()?true:false;
    }
    vector<string> generateParenthesis(int n) {
        f(n,n,"");
        vector<string>ans;
        for(string str:all){
            if(check(str)){
                ans.push_back(str);
            }
        }
        return ans;
    }
};
int main() {
   Solution().generateParenthesis(3);
    return 0;
}