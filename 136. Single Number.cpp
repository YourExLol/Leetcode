## Problem Statement ##
## 136. Single Number
## https://leetcode.com/problems/single-number/

############################################### Code begins here ##############################################################

class Solution {
public:
    int singleNumber(vector<int>& a) {
        //bitwise xorbw same no is 0 and with 0 is same no
        int n=a[0];
        for(int i=1;i<a.size();i++) n=n ^ a[i];
        return n;
    }
};
