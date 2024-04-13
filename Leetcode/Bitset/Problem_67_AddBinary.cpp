#include<iostream>
#include<vector>
#include <bitset>
using namespace std;
class Solution1 {
public:
    string addBinary(string a, string b) {
        string ans;
        int prev=0;
        int la=a.size()-1,lb=b.size()-1;
        while(la>=0||lb>=0){
            int ca=la<0?0:a[la]-'0';
            int cb=lb<0?0:b[lb]-'0';
            int curr=ca+cb+prev;
            if(curr>1){
                ans='0'+ans;
                prev=1;
            }
            else if(curr==1){
                ans='1'+ans;
                prev=0;
            }
            else{
                ans='0'+ans;
                prev=0;
            }
            la--;lb--;
        }
        return prev?'1'+ans:ans;
        
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        bitset<4000>na{a},nb{b};
        bitset<4000>sum,carry;
        while(nb.any()){
            sum=na^nb;
            carry=na&nb;
            carry<<=1;
            na=sum;
            nb=carry;
        }
        string ans=na.to_string();
        int pos=ans.find('1');
        if(pos!=string::npos){
            return ans.substr(pos);
        }
        return "0";
    }
};
int main() {
    return 0;
}