#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        if(i==s.size())return true;
        return false;

    }
};
int main() {
    cout<<Solution(). isSubsequence("axc","ahbgdc");
    return 0;
}