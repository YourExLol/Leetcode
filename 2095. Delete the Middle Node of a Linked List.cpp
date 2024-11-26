## Problem Statement ##
## 2095. Delete the Middle Node of a Linked List
## https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode* deleteMiddle(ListNode* head) {

        //reach middle //swap with next;
        if(head==NULL || head->next==NULL) return NULL;

        //2 nodes
        if(head->next->next==NULL) {
            head->next=NULL;
            return head;
        }

        //2+ Nodes
        ListNode *slow=head,*fast=head;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        //copy val with next and delete next

        slow->val=slow->next->val;

        slow->next=slow->next->next;

        return head;
    }
};
