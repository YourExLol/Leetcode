## Problem Statement ##
## 976. Largest Perimeter Triangle
## https://leetcode.com/problems/largest-perimeter-triangle/

############################################### Code begins here ##############################################################

class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        sort(a.begin(),a.end(),greater<int>());

        for(int i=0;i<a.size()-2;i++){
        if(a[i]<(a[i+1]+a[i+2])) return a[i]+a[i+1]+a[i+2];
        }
        return 0;
        
    }
};
