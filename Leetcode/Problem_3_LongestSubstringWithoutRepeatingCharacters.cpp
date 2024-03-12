#include<iostream>
using namespace std;
class Solution {
    vector<bool>ascii;
    int maxLength;
    
public:
    Solution():ascii(128,false),maxLength(0){

        }
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.size();
        while(j<n){
            if(!ascii[s[j]]){
                ascii[s[j]]=true;
                maxLength=max(maxLength,j-i+1);
                j++;
            }else{
                ascii[s[i]]=false;
                i++;
            }
        }
        return maxLength;
    }
};
int main() {
    cout<<Solution().lengthOfLongestSubstring("abcabcbb");
    return 0;
}