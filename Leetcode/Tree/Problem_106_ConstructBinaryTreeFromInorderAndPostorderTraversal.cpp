#include<iostream>
#include <utility>
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
    vector<int> inorder,postorder;
    TreeNode* construct(int il,int ir,int pl,int pr){
        if(il>ir||pl>pr){
            return nullptr;
        }
        TreeNode* curr=new TreeNode(postorder[pr]);

        for(int m=il;m<=ir;m++){
            if(inorder[m]==postorder[pr]){
                curr->left=construct(il, m-1, pl, pl+(m-il-1));
                curr->right=construct(m+1, ir, pl+(m-il), pr-1);
            }
        }
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        this->inorder=std::move(inorder);
        this->postorder=std::move(postorder);
        return construct(0, n-1, 0, n-1);
    }
};
int main() {
    return 0;
}