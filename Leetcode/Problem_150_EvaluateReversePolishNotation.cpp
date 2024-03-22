#include<iostream>
#include <ostream>
#include <string>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;
class WAttempt {
public:
    
    int evalRPN(vector<string>& tokens) {
        int dict[129];
        dict['+']=1;
        dict['-']=1;
        dict['*']=2;
        dict['/']=2;
        int n=tokens.size();
        stack<string>numbers;
        stack<string>c;
        for(int i=0;i<n;i++){
           if(tokens[i][0]>='0'&&tokens[i][0]<='9'){
            //说明是数字
            numbers.push(tokens[i]);
            continue;
           }
           string topc=c.top();
           string currc=tokens[i];
           if(dict[topc[0]]>=dict[currc[0]]){
            string p1=numbers.top();
            if(!numbers.empty())numbers.pop();
            string p2=numbers.top();
            if(!numbers.empty())numbers.pop();
            string result=p1+topc+p2;
            numbers.push(result);
            if(!c.empty())c.pop();
           }
            c.push(currc);
        }
        cout<<numbers.top();
        return 0;
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>c;
        int n=tokens.size();
        for(int i=0;i<n;i++){
           if(tokens[i]=="+"){
                int p1=c.top();
                c.pop();
                int p2=c.top();
                c.pop();
                int result=p1+p2;
                c.push(result);
                continue;
           }
           if(tokens[i]=="-"){
               int p1=c.top();
                c.pop();
                int p2=c.top();
                c.pop();
                int result=p1-p2;
                c.push(result);
                continue; 
           }
           if(tokens[i]=="*"){
            int p1=c.top();
                c.pop();
                int p2=c.top();
                c.pop();
                int result=p1*p2;
                c.push(result);
                continue;
           }
            if(tokens[i]=="/"){
                   int p1=c.top();
                c.pop();
                int p2=c.top();
                c.pop();
                int result=p1/p2;
                c.push(result);
                continue;
            }
            c.push(stoi(tokens[i]));
        }
        return c.top();
    }
};
int main() {
   vector<string>arr{"4","13","5","/","+"};
   Solution().evalRPN(arr) ;
    return 0;
}