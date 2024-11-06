## Problem Statement ##
## 4. Median of Two Sorted Arrays
## https://leetcode.com/problems/median-of-two-sorted-arrays/description/
## Explanation: https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
############################################### Code begins here ##############################################################

############  Solution 1 : T~O(min(n,m)) Solution

class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
    

    int x1 = n / 2;
    int x2 = ((m + n + 1) / 2) - x1;

    // Loop until we find the correct partition
    while (true) {
        // Handle out of bounds checks
        int leftA = (x1 == 0) ? INT_MIN : arr[x1 - 1];
        int rightA = (x1 == m) ? INT_MAX : arr[x1];
        int leftB = (x2 == 0) ? INT_MIN : brr[x2 - 1];
        int rightB = (x2 == n) ? INT_MAX : brr[x2];

        // Check if we found the correct partition
        if (leftA <= rightB && leftB <= rightA) {
            // Calculate the median
            if ((m + n) % 2 == 0) {
                return (max(leftA, leftB) + min(rightA, rightB)) / 2;
            } else {
                return  max(leftA, leftB);
            }
            break;
        }
        // Adjust x1 and x2 based on partition condition
        else if (leftA > rightB) {
            x1--; // Move x1 left
            x2++; // Move x2 right
        } else {
            x1++; // Move x1 right
            x2--; // Move x2 left
        }
    }
    }
};

########## Solution 2 : T~O(log(min(n,m)) ###############################################################################

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);

        int start=0;
        int end=n1;

        while(start<=end){  //binary search
            int i1=(start+end)/2;
            int i2=(n1+n2+1)/2-i1;

            //out of bound handling 
            int max1=(i1==0)?INT_MIN:nums1[i1-1];
            int min1=(i1==n1)?INT_MAX:nums1[i1];
            int max2=(i2==0)?INT_MIN:nums2[i2-1];
            int min2=(i2==n2)?INT_MAX:nums2[i2];

            //correct partition found?

            if(max1<=min2 && max2<=min1){
                if((n1+n2)%2==0) return (max(max1,max2)+min(min1,min2))/2.0;
                else return  max(max1,max2);
            }
            else if(max1>min2) end=i1-1;
            else start=i1+1;
        }//while loop ends here
        return 0;
      
    } //fn ends here
