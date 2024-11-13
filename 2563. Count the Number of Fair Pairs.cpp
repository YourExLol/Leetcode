## Problem Statement ##
## 2563. Count the Number of Fair Pairs
## https://leetcode.com/problems/count-the-number-of-fair-pairs/

############################################### Code begins here ##############################################################

class Solution {
public:
    long long countFairPairs(vector<int>& a, int lower, int upper) {
        long long ans=0;
        sort(a.begin(),a.end()); //so we can apply binary search

        // we gonna find range (arr[a],arr[b]) for each i that satisfy the conditions
        //suppose we have 0, a,b,4,x,y,7,z, now suppose 4 to 7 range satisfy conditions which can found using lower and upper bound but in case 4,4,x,x,7,7 we need lower bound for lower and upper for upper bound
        for(int i=0;i<a.size()-1;i++){
            auto low=lower_bound(a.begin()+i+1,a.end(),lower-a[i]);
            auto high=upper_bound(a.begin()+i+1,a.end(),upper-a[i]);
            ans+=high-low;
        }
        return ans;
    
    }
};
