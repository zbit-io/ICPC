#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> >minSum(n,vector<int>(m));
        //状态转移方程:f[i][j]=min{f[i-1][j],f[i][j+1]}+grid[i][j];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0)minSum[0][0]=grid[0][0];
                else if(j==0)minSum[i][j]=minSum[i-1][j]+grid[i][j];
                else if(i==0)minSum[i][j]=minSum[i][j-1]+grid[i][j];
                else{
                    minSum[i][j]=min(minSum[i-1][j],minSum[i][j-1])+grid[i][j];
                }
            }
        }
        return minSum[n-1][m-1];
    }
};
int main() {
    vector<vector<int> >grid={{1,2,3},{4,5,6}};
    //{{1,3,1},{1,5,1},{4,2,1}};
   cout<<Solution(). minPathSum(grid);
    return 0;
}