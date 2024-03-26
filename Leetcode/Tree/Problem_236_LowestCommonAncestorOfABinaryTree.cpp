#include<iostream>
#include <stack>
#include<vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool isFind=false;
    void f(TreeNode* root,const TreeNode*const target,stack<TreeNode*>& s){
        if(!root||isFind)return;
        s.push(root);
        if(root->val==target->val){
            isFind=true;
            return;
        }
        f(root->left,target,s);
        f(root->right,target,s);
        s.pop();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> sp,sq;
       f(root, p, sp);
       isFind=false;
       f(root,q,sq);
       while(sp.size()>sq.size()){
        sp.pop();
       }
       while(sp.size()<sq.size()){
        sq.pop();
       }
       sq.pop();
       return sq.top();
    }
};
int main() {
    return 0;
}