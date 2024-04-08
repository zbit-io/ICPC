#include<iostream>
#include <vector>
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
    TreeNode* construct(int prel,int prer,int inl,int inr,const vector<int>& pre,const vector<int>& in){
       if(prel>prer||inl>inr){
            return nullptr;
       } 

       TreeNode *curr=new TreeNode(pre[prel]);
       for(int i=inl;i<=inr;i++){
            if(pre[prel]==in[i]){
                curr->left=construct(prel+1, prel+(i-inl), inl, i-1, pre, in);
                curr->right=construct(prel+(i-inl)+1, prer, i+1, inr, pre, in);
                break;
            }
       }
       return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(0, preorder.size()-1,0,inorder.size()-1, preorder, inorder);
    }
};
int main() {
    
    return 0;
}