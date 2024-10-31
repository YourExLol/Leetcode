## Problem Statement ##
## 2. Add Two Numbers
## https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int digit,carry;
        int sum=l1->val+l2->val;
        carry=(sum>9)?1:0;
        digit=sum%10;
        l1=l1->next;
        l2=l2->next;


        //First Node with First Digit
        ListNode *ans=new ListNode(digit);
        ListNode *it=ans;
      //Above for Rest Numbers
        while(l1!=NULL || l2!=NULL){
            int l1_val=(l1==NULL)?0:l1->val;
            int l2_val=(l2==NULL)?0:l2->val;
          //Like we did above
            sum=l1_val+l2_val+carry;
            digit=sum%10;
            carry=(sum>9)?1:0;
          //New Node Creation and addition to answer node
            ListNode *temp=new ListNode(digit);
            it->next=temp;
            it=temp;
          //Iterating l1 and l2
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        } //while ends here
          //incase adding last digits result in carry=1
           if(carry==1) {
            ListNode *temp=new ListNode(1);
            it->next=temp;
           }
            return ans;
    }//fn ends here
};
