#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int m;
    string w;
    vector<vector<bool> >isVisited;
    vector<vector<char>> board;
    bool isExist=false;
    void dfs(int p,int i,int j){
        // if(i==m||j==m||i<0||j<0)return;
        
        // if(w[p]!=board[i][j])return;
        
        // if(isVisited[i][j])return;

        if (isExist || i < 0 || j < 0 || i == m || j == n || isVisited[i][j] || w[p] != board[i][j]) return;
        if (p == w.size() - 1) {
            isExist = true;
            return;
        }
        
        isVisited[i][j]=true;
        dfs(p+1,i,j+1);//right
         dfs(p+1,i,j-1); //left
          dfs(p+1,i+1,j);//down
           dfs(p+1,i-1,j);//up
           isVisited[i][j]=false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        w=word;
        isVisited=vector<vector<bool> >(m,vector<bool>(m,false));
        this->board=board;
        dfs(0, 0, 0);
        return isExist;
    }   
};
int main() {
   Solution(). 
    return 0;
}