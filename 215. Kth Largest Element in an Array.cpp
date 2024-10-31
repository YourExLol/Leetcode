## Problem Statement ##
## 215. Kth Largest Element in an Array
## https://leetcode.com/problems/kth-largest-element-in-an-array/

############################################### Code begins here ##############################################################

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(), nums.begin() + k); //create min heap of K elements
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){      //currently pq.top() is k the largest element but if there exist a larger element than it, it becomes k+1th largest element. so we pop out. So pq.top() will always have kth largest element
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
