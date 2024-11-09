## Problem Statement ##
## 2816. Double a Number Represented as a Linked List
## https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

############################################### Code begins here ##############################################################

lass Solution {
public:
    int carryNo(ListNode* head,int &carry){
        if(head==NULL) return 0;
        carry=carryNo(head->next,carry);
        int temp=(2*head->val)+carry;
        if(temp>9) carry=1;
        else carry =0;
        head->val=temp%10;
        return carry;
    }

    ListNode* doubleIt(ListNode* head) {
        int a=0;
        if(carryNo(head,a)>0) {
            ListNode * temp=new ListNode(1,head);
            head=temp;
        }
        return head;
    }
};
