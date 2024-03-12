#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        for(int i=n;i>0;i--){
            int t=0;
            for(int j=0;j<n;j++){
                t=citations[j]>=i?t+1:t;
            }
            if(t>=i)return i;
        }
        return 0;
    }
};
int main() {
    vector<int> citations{3,0,6,1,5};
    cout<<Solution().hIndex(citations);
    return 0;
}