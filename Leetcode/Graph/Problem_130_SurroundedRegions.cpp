#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int m,n;
    vector<vector<bool> >isx;
    void mark(int i,int j,const vector<vector<char>>& board){
        if(i<0||j<0||i>=m||j>=n||board[i][j]=='X')return;
        isx[i][j]=false;
        mark(i, j+1, board);
        mark(i,j-1,board);
        mark(i-1,j,board);
        mark(i+1, j, board);
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        isx=vector<vector<bool> >(m,vector<bool>(n,true));
        for(int i=0;i<m;i++){
          mark(i, 0, board);
          mark(i, n-1, board);
        }
        for(int j=0;j<n;j++){
            mark(0, j, board);
            mark(m-1, j, board);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=isx[i][j]?'X':'0';
            }
        }
    }
};
int main() {
    return 0;
}