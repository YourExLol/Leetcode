## Problem Statement ##
## 206. Reverse Linked List
## https://leetcode.com/problems/reverse-linked-list/

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
    
    ListNode* reverseList(ListNode* head) {

        ///////Iterative Approach/////////////////////////////
        ListNode *curr=head,*prev=NULL,*tail=NULL;

        while(curr!=NULL){
            tail=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tail;
        }

        return prev;

        ///////////////////////////////////////////////////////

        //Recursive Solution/////////////////////////////////
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *new_head=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;

        return new_head;
        //////////////////////////////////////////////////////
    }
};
