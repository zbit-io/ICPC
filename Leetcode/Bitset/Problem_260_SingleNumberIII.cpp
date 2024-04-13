#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_result=0;
        for(const int&num:nums){
            xor_result^=num;
        }
        unsigned int devide_num=xor_result^-xor_result;
        int result1=0,result2=0;
        for(const int&num:nums){
            if(num&devide_num){
                result1^=num;
            }
            else{
                result2^=num;
            }
        }
        return vector<int>{result1,result2};
    }
};
int main() {
    return 0;
}