#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> ans(32);
        for (int num:nums) {
            unsigned int curr=1<<31;
            int j=0;
            while (curr) {
                ans[j]+=(curr&num)?1:0;
                curr>>=1;
                j++;
            }
        }
        bitset<32> temp;
        for(int i=0;i<32;i++){
            if(ans[31-i]%3){
                temp.set(i);
            }

        }
        return static_cast<int>(temp.to_ulong());
    }
};
int main() {
   
    return 0;
}