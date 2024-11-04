## Problem Statement ##
## 1991. Find the Middle Index in Array
## https://leetcode.com/problems/find-the-middle-index-in-array/

############################################### Code begins here ##############################################################

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int sum=0;
        for(auto x:nums) sum+=x;
        int temp_sum=0;

        if(nums.size()==1) return 0;

        for(int i=0;i<nums.size();i++){
                  if((2*temp_sum+nums[i])==sum) return i;
                  temp_sum+=nums[i];
                  //cout<<temp_sum<<endl;
        }

        return -1;
    }
};
