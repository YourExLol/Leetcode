## Problem Statement ##
## 876. Middle of the Linked List
## https://leetcode.com/problems/middle-of-the-linked-list/description/

############################################### Code begins here ##############################################################

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast=head;

        while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        head=head->next;
        }      
         return head;
    }
   
};
