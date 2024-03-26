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
    int f(TreeNode* root){
        if(!root)return 0;
        int dl=f(root->left);
        int dr=f(root->right);
        return max(dl,dr)+1;
    }
    int maxDepth(TreeNode* root) {
        return f(root);
    }
};
int main() {
//    Solution(). 
    return 0;
}