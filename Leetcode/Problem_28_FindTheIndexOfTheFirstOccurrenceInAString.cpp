#include<bits/stdc++.h>
using namespace std;
class Solution1 {
    /**
    *@Time:2023-09-26 08:45:58
    *@Status:AC
    *@Approach:暴力匹配
    *@Complexity Analysis:O(n*m)
    *@Example usage:
    **/
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            bool flag=true;
            for(int j=0;j<needle.size();j++){
                if(i+j>=haystack.size()||haystack[i+j]!=needle[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return i;
            }
            
        }
        return -1;
    }
};
typedef unsigned long long ull;
ull RabinKarp(string s,string target){
    const ull MOD=(1ULL<<61)-1;
    const ull N=1e9+7;
    int sl=s.size();
    int tl=target.size();
    ull hs=0;
    ull ht=0;
    ull nm=1;
    if(sl<tl)return -1;
    for(int i=0;i<tl;i++){
        nm=(N*nm);
    }
    for(int i=0;i<tl;i++){
        ht=(ht*N+target[i]);
        hs=(hs*N+s[i]);
    }
  
    for(int i=0;i+tl<=sl;i++){//之所以要取等是因为我们是先计算后判断
        if(hs==ht)return i;
        if(i+tl<sl)hs=hs*N-s[i]*nm+s[i+tl];
    }

    
    return -1;

}
class Solution {
public:
    int strStr(string haystack, string needle) {
        return RabinKarp(haystack,needle);
    }
};
int main() {
    cout<<Solution().strStr("mississippi","issi");
    return 0;
}