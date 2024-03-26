#include<iostream>
#include <string>
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
    int sum=0;
    void f(TreeNode* node,string num){
    if(!node)return;
    num=num+to_string(node->val);
    if(!node->left&&!node->right){
        sum+=stoi(num);
        return;
    }
    
    f(node->left,num);
    f(node->right, num);

}
public:
    int sumNumbers(TreeNode* root) {
        f(root, "");
        return sum;
    }
};
int main() {
    return 0;
}