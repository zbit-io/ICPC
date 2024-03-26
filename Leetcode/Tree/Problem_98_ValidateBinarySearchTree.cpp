#include<iostream>
#include <limits>
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
    bool f(TreeNode* root,int mi,int ma){
        if(!root)return true;
        if(root->val<mi||root->val>ma){
            return false;
        }
        return f(root->left,mi,root->val)&&f(root->right,root->val,ma);

    }
    bool isValidBST(TreeNode* root) {
        return f(root,numeric_limits<int>::min(),numeric_limits<int>::max());
    }
};
int main() {
    return 0;
}