#include <cstddef>
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
    bool result=true;
public:
    void f(TreeNode*p,TreeNode*q){
        if(!p&&!q)return;
        if(p==nullptr&&q||p&&q==nullptr||p->val!=q->val){
            result=false;
        }
        isSameTree(p->left, q->left);
        isSameTree(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        f(p,q);
        return result;
    }
};
int main() {
//    Solution().
    return 0;
}