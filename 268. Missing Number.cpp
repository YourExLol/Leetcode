## Problem Statement ##
## 268. Missing Number
## https://leetcode.com/problems/missing-number/

############################################### Code begins here ##############################################################

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n=nums.size();
        int sum=0;
        for(auto x:nums) sum+=x;
        return n*(n+1)/2 - sum;
        
    }
};
