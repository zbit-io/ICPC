#include<iostream>
#include <unordered_map>
#include<vector>
#include<map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    unordered_map<Node*, Node*>dict;
    Node* f(Node* node){
        if(node==nullptr){
            return nullptr;
        }
        if(!dict.count(node)){
            Node* newNode=new Node(node->val);
            newNode->next=f(node->next);
            newNode->random=f(node->random);
            dict[node]=newNode;
            return newNode;
        }
        return dict[node];
    }
public:
    Node* copyRandomList(Node* head) {
        return f(head);
    }
};
int main() {
   Solution(). 
    return 0;
}