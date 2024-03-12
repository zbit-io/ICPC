#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.size()-1;
        while(j>=0&&s[j]==' ')j--;
            string ans="";
            while(j>=0&&s[j]!=' '){
                ans=s[j]+ans;
                j--;
            }
        return ans.size();
    }
};
int main() {
    
   cout<<Solution(). lengthOfLastWord("   fly me   to   the moon  ");
    return 0;
}