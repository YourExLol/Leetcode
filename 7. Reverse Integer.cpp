## Problem Statement ##
## 7. Reverse Integer
## https://leetcode.com/problems/reverse-integer/

############################################### Code begins here ##############################################################

class Solution {
public:
    int reverse(int x) {
        int rev=0;

        while(x!=0){
            if(rev>INT_MAX/10) return 0; //to handle overflow
            if(rev<INT_MIN/10) return 0;  //to handle overflow
            rev=10*rev+(x%10);
            
            x=x/10;
        }
        return rev;
    }
};
