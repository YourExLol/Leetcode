## Problem Statement ##
## 560. Subarray Sum Equals K
## https://leetcode.com/problems/subarray-sum-equals-k/

############################################### Code begins here ##############################################################

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Presum array : sum of any subarray(i,j)=target(k)=Cummulative sum(j)-cummaltive sum (i-1)
        //cummlative sum(i-1)=Cummulative sum(j)-k;
        //we store it in unordered map for faster search
        int c_sum=0;
        int ans=0;
        unordered_map<int,int> um;
        um[0]=1;

        for(auto x:nums){
            c_sum+=x;
            if(um.count(c_sum-k)==1) ans+=um[c_sum-k];
            
            um[c_sum]++;
            
        }
        return ans;
    }
};
