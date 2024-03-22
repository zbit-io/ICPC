#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool>row(m,false);
        vector<bool>col(n,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<m;i++){
            if(row[i]==1){
                for(int p=0;p<n;p++){
                    matrix[i][p]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(col[i]==1){
                for(int p=0;p<m;p++){
                    matrix[p][i]=0;
                }
            }
        }
    }
};
int main() {
//    Solution().
    return 0;
}