#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

 struct UniFind{
             vector<vector<pair<short,short> > > _map;
             vector<vector<bool> > _color;
             vector<vector<bool> > is_visited;
            UniFind(const vector<vector<char>>& board){
                int m=board.size();
                int n=board[0].size();
                _map=  vector<vector<pair<short,short > > >(m,vector<pair<short,short> >(n,make_pair(-1,-1)));
                _color= vector<vector<bool> >(m,vector<bool>(n,false));
                is_visited=vector<vector<bool> >(m,vector<bool>(n,false));
                for(int i=0;i<board.size();i++){
                    for(int j=0;j<board[i].size();j++){
                        _map[i][j]=make_pair(i,j);
                       
                       
                    }
                }
               
            }
            const pair<short,short> find(short x,short y){
                auto pair=_map[x][y];
                return _map[x][y]=pair.first==x&&pair.second==y?_map[x][y]:find(pair.first,pair.second);
            }
            
            void merge(pair<short,short> a,pair<short,short> b){
                _map[a.first][a.second]=_map[b.first][b.second];
        
            }
        };
        void f( UniFind& uf,const vector<vector<char>>& board, int a,int b,int c,int d,const int& m,const int &n){
            for(int i=b;b<=d;i++){
                if(board[a][i]=='O'){
                    if(board[a+1][i]=='O'&&uf.is_visited[a+1][i]==false){
                        uf.merge(make_pair(a+1,i),make_pair(a,i));
                        
                    }
                }
            }
        }
    void solve(vector<vector<char>>& board) {
       UniFind uf(board);
        for(int )
       
    }
};
int main(){
    Solution solution;
    vector<vector<char>> board{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solution.solve(board);
    for(auto i:board){
        for(auto j:i){
            cout<<"j"<<" ";
        }
        cout<<'\n';
    }
}