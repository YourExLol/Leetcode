## Problem Statement ##
## 15. 3Sum
## https://leetcode.com/problems/3sum/description/

############################################### Code begins here ##############################################################

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> v;
        set<vector<int>> s; // to store non duplicates

        //sort to use 2 pointers tech
        //fix first no, and use two pointers on other two nos
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) break; //incase the starting no is >0 we will never find a triplet cause all nos are postive after that since we have sorted the array.
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                if((nums[i]+nums[j]+nums[k])==0) {
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;k--;
                    }
                else if((nums[i]+nums[j]+nums[k])>0) k--;
                else j++;
            }
            
        }//for loop ends here

        for(auto x:s)
            v.push_back(x);
        return v;

    }//fn ends here
};
