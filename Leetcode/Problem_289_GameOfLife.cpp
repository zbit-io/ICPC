#include<iostream>
#include <utility>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    // deque<pair<int,int> >dq;
    // void bfs(int i,int j,const vector<vector<int> >&board,vector<vector<int> >&ans){
    //     // deque<pair<int,int> >

        
    //     for(int a=-1;a<=1;a++){
    //         for(int b=-1;b<=1;b++){
    //             if(a==0&&b==0)continue;
    //             dq.push_back(make_pair(i+a, j+b));
    //         }
    //     } 
        
    // }
    int m,n;
    bool check(int i,int j,const vector<vector<int> >&board){
        int alive=0;
         for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                if(a==0&&b==0)continue;
                if(i+a<0||j+b<0||i+a>=m||j+b>=n)continue;
                if(board[i+a][j+b])alive++;
            }
        } 
        if(board[i][j]==true&&(alive==2||alive==3))return true; 
        if(board[i][j]==false&&alive==3)return true;
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int> >temp(board);
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for (int j=0; j<n; j++) {
                board[i][j]=check(i, j, temp);
            }
        }
    }
};
int main() {
//    Solution(). 
    return 0;
}