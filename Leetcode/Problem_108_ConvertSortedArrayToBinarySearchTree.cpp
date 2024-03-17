/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
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
    TreeNode* constructTree(const vector<int>& nums,int i,int j){
        if(j<i||i>j||i<0||j>=nums.size())return nullptr;
        int root=(i+j)/2;
        TreeNode* curr=new TreeNode(nums[root]);
        curr->left=constructTree(nums, i, root-1);
        curr->right=constructTree(nums, root+1, j);
        return curr;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTree(nums, 0, nums.size()-1);
    }
};
using namespace std;
int main(){
    vector<int>arr{-10,-3,0,5,9};
    Solution().sortedArrayToBST(arr);
    return 0;
}