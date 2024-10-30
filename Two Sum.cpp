## Problem Statement ##
## Two Sum
## https://leetcode.com/problems/two-sum/description/

############################################### Code begins here ##############################################################

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        multimap<int,int> um;
        for(int i=0;i<nums.size();i++){
            um.insert({nums[i],i});
        }

         for (int i = 0; i < nums.size(); i++) {
             int complement = target - nums[i];
        auto range = um.equal_range(complement);
        for (auto it = range.first; it != range.second; ++it) {
            if (it->second != i) { // Ensure indices are not the same
                v.push_back(it->second); // Push back the index of the complement
                v.push_back(i); // Push back the current index
                return v; 
            }
        }
         }
        return v;
    }
};
