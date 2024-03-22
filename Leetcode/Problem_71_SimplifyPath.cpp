#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        stack<string>s;
        string t="";
        path=path+'/';
        for(int i=0;i<n+1;i++){
            if(path[i]=='/'){
                if(t==".."){
                    t="";
                    if(!s.empty())s.pop();
                    continue;
                }
                if(t=="."){
                    t="";
                    continue;
                }
                if(!t.empty()){
                    s.push(t);
                }
                t="";
                continue;
            }
            t=t+path[i];   
        }
        string ans;
        while (!s.empty()) {
            ans="/"+s.top()+ans;
            s.pop();
        }
        if(ans=="")return "/";
        return ans;
    }
};
int main() {
//    Solution(). 
    return 0;
}