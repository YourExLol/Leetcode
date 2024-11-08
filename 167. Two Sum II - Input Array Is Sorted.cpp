## Problem Statement ##
## 167. Two Sum II - Input Array Is Sorted
## https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

############################################### Code begins here ##############################################################

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        //2 pointer Approach
        int i=0,j=numbers.size()-1;
        
        while(i<j){
            if(numbers[i]+numbers[j]==target) break;
            else if(numbers[i]+numbers[j]>target) j--;
            else i++;
        }
        return {i+1,j+1};
    }
};
