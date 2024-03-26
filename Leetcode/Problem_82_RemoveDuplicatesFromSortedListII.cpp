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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* temp=head->next,*prev=head,*pp=&dummy;
        while(temp){
            if(temp->val==prev->val){
                temp=temp->next;
                continue;
            }
            pp->next=temp;
            pp=temp;
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};
int main() {
   Solution(). 
    return 0;
}