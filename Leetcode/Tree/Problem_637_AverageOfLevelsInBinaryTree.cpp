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
    vector<double>ans;
    void f(queue<TreeNode*>& q){
        if(q.empty())return;

        double sum=0,count=0;
        queue<TreeNode*> nq;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)nq.push(curr->left);
            if(curr->right)nq.push(curr->right);
            sum+=curr->val;
            count++;
        }
        ans.push_back(sum/count);
        f(nq);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        f(q);
        return ans;
    }
};
int main() {
    return 0;
}