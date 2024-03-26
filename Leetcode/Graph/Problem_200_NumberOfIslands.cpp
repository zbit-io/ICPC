#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int m,n;
    void fill(int i,int j,vector<vector<char> >& matrix){
        if(i<0||j<0||i>=m||j>=n||matrix[i][j]=='0')return ;
        matrix[i][j]='0';
        fill(i, j+1, matrix);
        fill(i, j-1, matrix);
        fill(i-1, j, matrix);
        fill(i+1, j, matrix);
    }
    bool check(int i,int j,vector<vector<char> >& matrix){
        if(matrix[i][j]=='1'){
            fill(i,j,matrix);
            return true;;
        }
        return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                count+=check(i, j, grid);
            }
        }
        return count;
    }
};