#include<iostream>
#include<vector>
#include<deque>
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
    vector<vector<int> >ans;
    void f(deque<TreeNode*> dq,bool postive){
        if(dq.empty())return;
        vector<int>temp;
        deque<TreeNode*>ndq;
        while(!dq.empty()){
            if(postive){
                TreeNode* curr=dq.front();
                dq.pop_back();
                temp.push_back(curr->val);
                if(curr->left)ndq.push_back(curr->left);
                if(curr->right)ndq.push_back(curr->right);
            }
            else{
               TreeNode* curr=dq.front();
                dq.pop_back();
                temp.push_back(curr->val);
                if(curr->left)ndq.push_front(curr->left);
                if(curr->right)ndq.push_front(curr->right); 
            }
            
        }
        ans.push_back(temp);
        f(ndq,!postive);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return ans;
        deque<TreeNode*>temp;
        temp.push_back(root);
        f(temp,true);
        return ans;
    }
};
int main() {
    return 0;
}