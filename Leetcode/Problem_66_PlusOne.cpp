#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]==9){
                if(i==0){
                    vector<int> ans{1};
                    for(auto p:digits){
                        ans.push_back(0);
                    }
                    return ans;
                }
                digits[i]=0;
            }
            else{
                digits[i]++;
                break;
            }
        }

        return digits;
    }
};
int main() {
    vector<int>digits{4,3,2,1};
   Solution().plusOne(digits);
    return 0;
}