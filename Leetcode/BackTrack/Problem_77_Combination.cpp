#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<int> >ans;
public:
    void f(int p,const int& k,const int& n,vector<int>& arr){
        if(p>n)return;
        if(p==n){
            ans.push_back(vector<int>(arr.begin(),arr.end()));
            return ;
        }
        for(int i=1;i<=n;i++){
            arr.push_back(i);
            f(p+1,k,n,arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        f(1,k,n,temp);
        return ans;
    }
};
int main() {
   Solution(). 
    return 0;
}