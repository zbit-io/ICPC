#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<char> >matrix;
public:
    string convert(string s, int numRows) {
        matrix=vector<vector<char> >(numRows,vector<char>(1000,' '));
        int j=0,p=1,n=s.size();
        if(n==1||numRows==1)return s;
        matrix[0][0]=s[0];
        string ans;
        cout<<"3we";
        while(p<n){
            int i=1;
            while(p<n&&i<numRows){
                matrix[i][j]=s[p];
                cout<<i<<" "<<p<<'\n';
                i++;p++;
            }
            j++;
            i=numRows-2;
            while(j<1000&&i>=0&&p<n){
                matrix[i][j]=s[p];
                j++;i--;p++; 
            } 
            
        }
        for(int a=0;a<numRows;a++){
            for(int b=0;b<j;b++){
                // cout<<matrix[a][b]<<" ";
                if(matrix[a][b]!=' '){
                    ans+=matrix[a][b];
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};
int main() {
   cout<<Solution(). convert("AB",1);
    return 0;
}