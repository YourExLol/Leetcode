## Problem Statement ##
## 116. 3Sum Closest
## https://leetcode.com/problems/3sum-closest/

############################################### Code begins here ##############################################################

class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
    
    //same as 2sum problem
    //fix 1st no and for rest 2 use 2 pointers
    //for every triplet consider check it abs distance with previous ans
    //if small change ans to current sum

    sort(a.begin(),a.end());
    int ans=200000;
    int size=a.size();

    for(int i=0;i<size;i++){
        int l=i+1,r=size-1;

        while(l<r){
            int _3sum=a[i]+a[l]+a[r];
            if(abs(_3sum-target)<abs(ans-target)) ans=_3sum;
            else if (_3sum>target) r--;
            else l++;
        }
    }//for loop ends here
    return ans;
    }
};
