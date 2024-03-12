#include<bits/stdc++.h>
using namespace std;

int main() {
    cout<<Solution().isIsomorphic("badc","baba") ;
    return 0;
}

class Solution {
    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;

public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            char cs = s[i];
            char ct = t[i];

            // 检查 s 到 t 的映射
            if (sToT.find(cs) != sToT.end()) {
                if (sToT[cs] != ct) {
                    return false;
                }
            } else {
                sToT[cs] = ct;
            }

            // 检查 t 到 s 的映射
            if (tToS.find(ct) != tToS.end()) {
                if (tToS[ct] != cs) {
                    return false;
                }
            } else {
                tToS[ct] = cs;
            }
        }

        return true;
    }
};
