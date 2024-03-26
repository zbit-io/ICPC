#include <algorithm>
#include <ios>
#include<iostream>
#include <stdexcept>
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
    bool check(TreeNode *l,TreeNode *r){
        if(!l&&!r){
            return true;;
        }
        if(!l||!r||l->val!=r->val){
            return false;
        }
        return check(l->left,r->right)&&check(l->right, r->left);
    }
   
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};
int main() {
//    Solution(). 
    return 0;
}