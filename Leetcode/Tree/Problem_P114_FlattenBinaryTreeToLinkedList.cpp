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
 
class Solution1 {
public:
    TreeNode *result;
    void f(TreeNode *root){
        if(!root)return;
        result->right=root;
        result->left = nullptr;
        result=result->right;
        // f(root->left);
        // f(root->right);
        TreeNode *left = root->left;  
        TreeNode *right = root->right; 
        f(left);
        f(right);
    }
    void flatten(TreeNode* root) {
        result=new TreeNode();
        TreeNode *backup=result;
        f(root);
        root=result->right;
    }
};

class Solution {
public:
    void f(TreeNode*prev,TreeNode *root){
        TreeNode* right=root->right;
        prev->left=nullptr;
        prev->right=root;
        prev=root;
        f(prev,root->left);
        f(prev,root->right);
    }
    void flatten(TreeNode* root) {
        TreeNode dummy(0);
        dummy.right=root;
    }
};
int main() {
    return 0;
}