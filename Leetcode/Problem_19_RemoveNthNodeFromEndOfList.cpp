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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int length=0;
        while(temp){
            length++;
            temp=temp->next;
        }
        temp=head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;
        int i=0;
        while(i<length-n){
            temp=temp->next;
            prev=prev->next;
            i++;
        }
        prev->next=temp->next;
        return dummy.next;
    }
};
int main() {

    return 0;
}