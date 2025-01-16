## Problem Statement ##
## 215. Kth Largest Element in an Array
## https://leetcode.com/problems/kth-largest-element-in-an-array/

############################################### Code begins here ##############################################################

//Priority Queue

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(), nums.begin() + k);
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

//Counting Sort

int kthSmallest(int arr[], int n, int k) {
    // First, find the maximum element in the array
    int max_element = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    // Create an array to store the frequency of each 
   // element in the input array
    int freq[max_element + 1] = {0};
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Keep track of the cumulative frequency of elements 
   // in the input array
    int count = 0;
    for (int i = 0; i <= max_element; i++) {
        if (freq[i] != 0) {
            count += freq[i];
            if (count >= k) {
                // If we have seen k or more elements, 
              // return the current element
                return i;
            }
        }
    }
    return -1;
}

// Quick Sort
