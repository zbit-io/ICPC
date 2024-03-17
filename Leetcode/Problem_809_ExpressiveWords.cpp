#include <_stdio.h>
#include<iostream>
#include <utility>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    void caculatePattern(vector<pair<char, int> >&spattern,const string& s){
                char c=s[0];int t=0;
                for(int i=0;i<s.size();i++){
                    if(c!=s[i]){
                        spattern.push_back(make_pair(c, t));
                        c=s[i];
                        t=0;
                    }
                    t++;
                }
                spattern.push_back(make_pair(c, t));


    }
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> spattern;
        caculatePattern(spattern, s);
        vector<vector<pair<char,int> > >patterns;
        for(string st:words){
            vector<pair<char,int> >temp;
            caculatePattern(temp, st);
            patterns.push_back(temp);
        }
        int ans=0;
        for(int i=0;i<patterns.size();i++){
            int l=patterns.size();
            if(patterns[i].size()!=spattern.size())continue;
            bool flag=true;
            const vector<pair<char, int> >& pattern=patterns[i];
            for(int j=0;j<spattern.size();j++){
                if(pattern[j].first!=spattern[j].first||spattern[j].second!=pattern[j].second&& spattern[j].second<3||spattern[j].second<pattern[j].second){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};
int main() {
    vector<string>word{"hello", "hi", "helo"};
    Solution(). expressiveWords("heeellooo", word);
    return 0;
}