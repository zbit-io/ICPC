#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool> >column(9,vector<bool>(10,false));
        vector<vector<bool> >row(9,vector<bool>(10,false));
        vector<vector<vector<bool> > >is3x3(3,vector<vector<bool>>(3,vector<bool>(10,false)));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int c=board[i][j]-'0';
                    if(!column[j][c])column[j][c]=1;
                    else return false;
                    if(!row[i][c])row[i][c]=1;
                    else return false;
                    if(!is3x3[i/3][j/3][c])is3x3[i/3][j/3][c]=1;
                    else return false;
                }
            }
        }
        return true;
    }
};
int main() {
    
    return 0;
}