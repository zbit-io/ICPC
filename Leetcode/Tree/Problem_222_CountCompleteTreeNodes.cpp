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
    bool check(TreeNode*root,int path,int deep){
       int bits=1<<(deep-1);
       while(root&&bits){
            if(bits&path){
                root=root->right;
            }
            else{
                root=root->left;
            }
            bits>>=1;
       } 
       return root!=nullptr;
    }
    int countNodes(TreeNode* root) {
        TreeNode* temp=root;
        int deep=0;
        while(temp){
            temp=temp->left;
            deep++;
        }
        int low=1<<deep;
        int high=(1<<(deep+1))-1;

        while(low<high){
            int mid=(low+high)>>1;

            if(check(root,mid,deep)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
int main() {
    return 0;
}