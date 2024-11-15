## Problem Statement ##
## 19. Remove Nth Node From End of List
## https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) {
            return NULL;
        }
        //hold the node n+1th node(end node) from start , and increment it with start=head till end node rreaches end node
        //now start node is n+1 th node from end
        //change its next to next-.next;

        
        int ctr=n;
        auto start=head;
        auto end=head;
        while(ctr--){
            end=end->next;
        }
        //incase you are deleting head node end node will become null
        if(end==NULL) return head->next;
        while(end->next!=NULL){
            start=start->next;
            end=end->next;
        }

        start->next=start->next->next;
        return head;

    }
};
