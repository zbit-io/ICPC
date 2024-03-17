#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* constructe(const vector<vector<int> >&grid,int a,int b,int c,int d){
    if(a==c&&b==d){
        return new Node(grid[a][b],true);
    }

    int val=grid[a][b];
    bool isLeaf=true;
    for(int i=a;i<=c;i++){
        for(int j=b;j<=d;j++){
            if(grid[i][j]!=val){
                isLeaf=false;
            }
        }
    }
    if(isLeaf){
        return new Node(grid[a][b],true);
    }
    Node* father=new Node();
    Node* topLeft=constructe(grid, a, b, (a+c)/2, (b+d)/2);
    Node* topRight=constructe(grid, a, (d+b)/2+1, (a+c)/2, d);
    Node* bottomLeft=constructe(grid, (a+c)/2+1, b, c, (b+d)/2);
    Node* bottomRight=constructe(grid, (a+c)/2+1, (b+d)/2+1, c, d);
    father->topLeft=topLeft;
    father->topRight=topRight;
    father->bottomLeft=bottomLeft;
    father->bottomRight=bottomRight;
    return father;

}
    Node* construct(vector<vector<int>>& grid) {
        return constructe(grid, 0,0, grid.size()-1, grid.size()-1);
    }
};
int main() {

   vector<vector<int> >grid{{1,1,0,0,0,0,1,1}
,{1,1,0,0,0,0,1,1}
,{0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,1,1},
{1,1,0,0,0,0,1,1}};
    Solution().construct(grid);


    return 0;
}