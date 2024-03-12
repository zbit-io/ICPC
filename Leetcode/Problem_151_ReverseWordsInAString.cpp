#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        const int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ')continue;
            string t;
            while(i>=0&&s[i]!=' '){
                t=s[i]+t;
                i--;
            }
            ans+=t+' ';
        };
        ans.pop_back();
        return ans;
        
    }
};

int main() {
    cout<<Solution(). reverseWords("the sky is blue");
    return 0;
}