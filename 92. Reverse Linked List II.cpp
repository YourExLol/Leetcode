## Problem Statement ##
## 92. Reverse Linked List II
## https://leetcode.com/problems/reverse-linked-list-ii/

############################################### Code begins here ##############################################################

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        //same as reverse linked list just hold previous and next nodes not part of reversal;

        ListNode *prev=NULL,*curr=head,*join=NULL,*next,*start=NULL;
        if(head==NULL || head->next==NULL || left==right) return head;

        int pos=1;
        //if(l==1) join=NULL;

        while(pos<left-1){
            curr=curr->next;
            pos++;
        }

        join=(left==1)?NULL:curr;
        start=(left==1)?head:curr->next;
        pos=(left==1)?1:++pos;
        curr=start;
        
        cout<<pos<<endl;
        while(pos<right+1){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            pos++;
        }
        cout<<pos;
        if(next!=NULL) start->next=next;
        if(join!=NULL) {join->next=prev; return head;} //incase head remains same
        return prev; //head changes cause l=1
         
        
    }
};
