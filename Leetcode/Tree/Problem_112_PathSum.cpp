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
        bool exist=false;
        int target;
        void f(int val,TreeNode *root){
            if(!root||exist)return;
            val+=root->val;
            if(!root->left&&!root->right){
                if(target==val){
                    exist=true;
                }
                return;
            }
            f(val,root->left);   
            f(val,root->right);
        }
        bool hasPathSum(TreeNode* root, int targetSum) {
            target=targetSum;
            f(0,root);
            return exist;
        }
};
int main() {

    return 0;
}