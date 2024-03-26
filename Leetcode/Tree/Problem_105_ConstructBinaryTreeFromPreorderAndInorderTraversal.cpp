#include<iostream>
#include<vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<int>preorder,inorder;
    void f(int a,int b,int i,int j){

        int rootval=preorder[i];
        for(int p=a;p<=b;p++){
            if(inorder[p]==rootval){
                int ll=p-a;
                int rl=b-p;
                f(a,i-1,i+1,j+());
                f(i+1,b);
            }
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder=preorder;
        this->inorder=inorder;
    }
};
int main() {
//    Solution(). 
    return 0;
}