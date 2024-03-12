#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<string,char>sTc;
    unordered_map<char,string>cTs;
public:
    bool wordPattern(string pattern, string s) {
        string substr="";
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                substr+=s[i];
                continue;
            }
            if(j>=pattern.size())return false;
            char patternChar=pattern[j];
            if(cTs.find(patternChar)!=cTs.end()){
                if(cTs[patternChar]!=substr){
                    return false;
                }
            }else{
                cTs[patternChar]=substr;
            }

            if(sTc.find(substr)!=sTc.end()){
                if(sTc[substr]!=patternChar)return false;
            }else{
                sTc[substr]=patternChar;
            }
            substr.clear();
            j++;
        }
        return true;
    }
};
int main() {
    cout<<Solution().wordPattern("abba","dog cat cat dog"); 
    return 0;
}