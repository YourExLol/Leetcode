## Problem Statement ##
## 540. Single Element in a Sorted Array
## https://leetcode.com/problems/single-element-in-a-sorted-array/

############################################### Code begins here ##############################################################

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans;
        ans=0;
      //No XOR withitself is 0 and with 0 is itself
        for(int x:nums){
            ans=ans^x;
        }
        return ans;
    }
};
