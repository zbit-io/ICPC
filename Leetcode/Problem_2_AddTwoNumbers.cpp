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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode*t1=l1;
        ListNode*t2=l2;
        ListNode*result=new ListNode;
        ListNode*backup=result;
        int in=0;
        while(t1&&t2){
            int curr=in+t1->val+t2->val;
            in=0;
            t1=t1->next;
            t2=t2->next;
            if(curr>=10){
                in=1;
                result->next=new ListNode(curr-10);
            }
            else{
                result->next=new ListNode(curr);
            }
            result=result->next;
        }
        while(t1){
            result->next=new ListNode(in+t1->val);
            in=0;
            result=result->next;
            t1=t1->next;
        }
        while(t2){
            result->next=new ListNode(in+t2->val);
            in=0;
            result=result->next;
            t2=t2->next;
        }
        return backup->next;
    }
};
int main() {
//    Solution(). 
    return 0;
}