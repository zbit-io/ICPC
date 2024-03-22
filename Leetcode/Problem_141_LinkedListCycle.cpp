#include<iostream>
#include<vector>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode* fast=head,*slow=head;
       if(head==nullptr||head->next==nullptr)return false;
       while(fast&&slow){
            fast=fast->next;
            if(fast){
                fast=fast->next;
            }
            slow=slow->next;
            if(fast==slow){
                return true;
            }   
       }
       return false;
    }
};

int main() {
   Solution(). 
    return 0;
}