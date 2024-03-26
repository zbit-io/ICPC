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
    int k=0;
    int result=-1;
    void f(int &p,TreeNode* root){
        if(!root||result!=-1)return;
        
        f(p,root->left);
        p++;
        if(p==k){
            result=root->val;
            return;
        }
        f(p,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        this->k=k;
        int t=0;
        f(t,root);
        return result;
    }
};
int main() {
    return 0;
}