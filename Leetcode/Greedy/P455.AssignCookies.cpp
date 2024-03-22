#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,ans=0;
        while(i<g.size()&&j<s.size()){
            if(g[i]<=s[j]){
                ans++;
                i++;
                j++;
                continue;
            }
            j++;
        }
        return ans;
    }
};
int main() {
//    Solution(). 
    return 0;
}