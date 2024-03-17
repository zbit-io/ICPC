#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int n,m;
    vector<int>ans;
public:
    void dfs(vector<vector<bool> >&isVisited,const vector<vector<int> >&matrix,int i,int j){
        
        if(i>=n||j>=m||i<0||j<0||isVisited[i][j])return;

        isVisited[i][j]=true;
        ans.push_back(matrix[i][j]);

        if(i-1<0||isVisited[i-1][j])dfs(isVisited, matrix, i, j+1);
        dfs(isVisited,matrix,i+1,j);
        dfs(isVisited, matrix, i, j-1);
        dfs(isVisited, matrix, i-1, j);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<bool> >isVisited(n,vector<bool>(m,false));
        dfs(isVisited, matrix, 0 , 0);
        return ans;
    }
};
int main() {
    vector<vector<int> >matrix;
   Solution(). spiralOrder(matrix);
    return 0;
}