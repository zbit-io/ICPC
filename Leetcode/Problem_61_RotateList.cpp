#include <cstddef>
#include<iostream>
#include<vector>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* front=head,*temp=head,*middle=nullptr,*last=nullptr;
        int length=0;
        while(temp){
            last=temp;
            length++;
            temp=temp->next;
        }
        ListNode dummy(0);
        dummy.next=head;
        temp=head;
        ListNode*pred=&dummy;
        for(int i=0;i<length-k;i++){
            temp=temp->next;
            pred=pred->next;
        }
        middle=temp;
        pred->next=nullptr;
        last->next=head;
        return middle; 
    }
};
int main() {
   Solution(). 
    return 0;
}