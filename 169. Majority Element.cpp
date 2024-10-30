## Problem Statement ##
## 169. Majority Element
## https://leetcode.com/problems/majority-element/?envType=problem-list-v2&envId=hash-table

############################################### Code begins here ##############################################################

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0];
        int ctr=1;

//if ctr==0 means the till range is not required to majority element as elements were cancelled.
//ctr!=0 we can continue the noraml process ie if seen ctr++ else ctr--

        for(int i=1;i<nums.size();i++){
            if(ctr==0){
                if(nums[i]==maj) ctr++;
                else {maj=nums[i];ctr++;}
            }
            else{
                if(nums[i]==maj) {ctr++;}
                else ctr--;
            }
        }//for loop ends here
        return maj;
    }
};
