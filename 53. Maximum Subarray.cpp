## Problem Statement ##
## 53. Maximum Subarray
## https://leetcode.com/problems/maximum-subarray/

############################################### Code begins here ##############################################################

class Solution {
public:
    int maxSubArray(vector<int>& a) {

        int f_ans=0,ans=0;
        int min_ele=INT_MIN;
        for(int i=0;i<a.size();i++){

            ans+=a[i];
            min_ele=max(min_ele,a[i]);
            f_ans=max(ans,f_ans);
            if(ans<=0){  //if an subarray has sum <=0 it can be discarded
                ans=0;

            }
        }
        cout<<f_ans<<endl;
        cout<<min_ele;

        //incase max_sum is -ve , whole array has -ve elements return max of it
        
        if(f_ans>0)
        return f_ans;
        else
        return min_ele;
        
    }
};
