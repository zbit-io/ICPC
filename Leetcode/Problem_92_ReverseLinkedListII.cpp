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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
        ListNode* curr=prev->next;
        ListNode* next;
        for(int i=left;i<right;i++){
            prev->next=curr->next;
            curr->next=prev->next;
            next->next=curr;
        }
        return dummy.next;
    }
};
int main() {
    return 0;
}