#include <algorithm>
#include <iostream>
#include <vector>
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
    ListNode* merge(ListNode*l1,ListNode*l2){
        ListNode dummy(0);
        ListNode* backup=&dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                backup->next=new ListNode(l1->val);
                l1=l1->next;
            }else{
                backup->next=new ListNode(l2->val);
                l2=l2->next;
            }
            backup=backup->next;
        }
        while(l1){
            backup->next=new ListNode(l1->val);
            backup=backup->next;
            l1=l1->next;
        }
        while(l2){
            backup->next=new ListNode(l2->val);
            backup=backup->next;
            l2=l2->next;
        }
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
    


        ListNode* slow=head,*fast=head;
        ListNode *pred=nullptr;
        while(fast&&fast->next){
            pred=slow;
            slow=slow->next;
            fast=fast->next->next;
            
        }
        pred->next=nullptr;

        ListNode *l1=sortList(head);
        ListNode *l2=sortList(slow);
        return merge(l1,l2);
    }
};