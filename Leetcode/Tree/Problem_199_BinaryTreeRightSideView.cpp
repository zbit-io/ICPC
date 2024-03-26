#include<iostream>
#include<vector>
#include<queue>
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
    vector<int>ans;
    void f(queue<TreeNode*> q){
        if(q.empty())return ;
        ans.push_back(q.back()->val);
        queue<TreeNode*>nq;
        while(!q.empty()){
            TreeNode* curr=q.front();
            if(curr->left)nq.push(curr->left);
            if(curr->right)nq.push(curr->right);
            q.pop();
        }
        f(nq);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        f(q);
        return ans;
    }
};
