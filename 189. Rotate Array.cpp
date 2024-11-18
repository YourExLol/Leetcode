## Problem Statement ##
## 189. Rotate Array
## https://leetcode.com/problems/rotate-array/

############################################### Code begins here ##############################################################

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        //consider two strip (1,k), and (k+1,n) rotating will reverse the order but neighbours wont change,rotate 2 times orientation will be same
        
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
    }
};
