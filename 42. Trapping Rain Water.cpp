## Problem Statement ##
## 42. Trapping Rain Water
## https://leetcode.com/problems/trapping-rain-water/

############################################### Code begins here ##############################################################

class Solution {
public:
    int trap(vector<int>& height) {
        //water to trap on any pillar, there must exist taller pillar on both sides.
        //Amount is dependent on tallest pillar on right side and left side.
        //Amount will be min(tallest_left_side,tallest_right_side)-height of pillar.

        vector<int> l_arr(height.size(),-1); //maintain left tallest pillar
        vector<int> r_arr(height.size(),-1); //maintain right tallest pillar

        for(int i=1;i<height.size();i++) l_arr[i]=max(l_arr[i-1],height[i-1]); //Tallest Pillar on left side
        for(int i=height.size()-2;i>=0;i--) r_arr[i]=max(r_arr[i+1],height[i+1]); //Tallest Pillar on right side

        int ans=0;
        for(int i=1;i<height.size()-1;i++) {  //start and end pillar wont contribute to any water trapping
            if(l_arr[i]>height[i] && r_arr[i]>height[i]) //water to trap on any pillar, there must exist taller pillar on both sides.
            ans+=min(l_arr[i],r_arr[i])-height[i];
        }

        return ans;
    }
};
