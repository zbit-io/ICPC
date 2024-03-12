#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    bool isPalindrome(string s) {
        string only;
        for(const char&c:s){
            if(c>='a'&&c<='z'||c>='0'&&c<='9'){
                only=only+c;
            }
            if(c>='A'&&c<='Z'){
                
                int gap='a'-'A';
                only=only+(char)((int)c+gap);
            }
        }
        bool flag=true;
        int i=0,j=only.size()-1;
        while(flag){
            if(i>j)return true;
            if(only[i]!=only[j]){
                return false;
            }
            i++;
            j--;
            
        }
    }
    //     string re;
    //     for(const auto&c:only){
    //         re=c+re;
    //     }
    //    // cout<<re<<" "<<only<<endl;
    //     return re==only;


};
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
       if(n==1){
           return true;
            // if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9')return true;
            // return false;
        }
        while(i<j){
            bool b1;
            do{
                b1=s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9';
                i++;
            } while(i<n&&!b1);
        
            do{
                b1=s[j]>='a'&&s[j]<='z'||s[j]>='A'&&s[j]<='Z'||s[j]>='0'&&s[j]<='9';
                j--;
            }while(j>=0&&!b1);
            char c1=s[i-1];
            char c2=s[j+1];
            if(i==n&&j==-1)return true;
            if(tolower(c1)!=tolower(c2)){
                return false;
            }
        }
        return true;
    }
};
int main() {
    cout<<Solution(). isPalindrome("a.");
        return 0;
}