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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small=new ListNode;
        ListNode *result=small;
        ListNode *big=new ListNode;
        ListNode *backupBig=big;
        ListNode* temp=head;
        while(temp){
            if(temp->val>=x){
                big->next=new ListNode(temp->val);
                big=big->next;
            }
            else{
                small->next=new ListNode(temp->val);
                small=small->next;
            }
            temp=temp->next;
        }
        result=result->next;
        backupBig=backupBig->next;
        if(!small)small->next=backupBig;
        return result;
    }
};
int main() {
   Solution(). 
    return 0;
}