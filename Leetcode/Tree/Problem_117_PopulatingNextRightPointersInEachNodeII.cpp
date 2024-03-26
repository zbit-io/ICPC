#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    void f(Node*pred,queue<Node*>&q){
        if(q.empty())return;
        Node* root=q.front();
        q.pop();
        if(!root)q.pop();
        pred->next=root;
        q.push(root->left);
        q.push(root->right);
        f(root,q);

    }
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        f(root,q);
        return root; 
    }
};
int main() {
    return 0;
}