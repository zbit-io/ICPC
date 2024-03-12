#include<bits/stdc++.h>
using namespace std;
class Solution {
    short dict[200];
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(const auto&i :magazine){
            dict[i]++;
        }
        for(const auto&i :ransomNote){
            if(dict[i]==0){
                return false;
            }
            dict[i]--;
        }
        return true;
    }
};
int main() {
    cout<<Solution().canConstruct("aa","aab");
    return 0;
}