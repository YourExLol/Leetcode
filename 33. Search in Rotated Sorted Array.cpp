## Problem Statement ##
## 33. Search in Rotated Sorted Array
## https://leetcode.com/problems/search-in-rotated-sorted-array/

############################################### Code begins here ##############################################################

class Solution {
public:
    int search(vector<int>& a, int target) {

        int start=0;
        int end=a.size()-1;

        //We check which part is sorted, and if target is found in sorted part then we can continue normal binary search, in case not found we eliminate the sorted part, and search it in unsorted part, 
        //the unsorted part is again divied into sorted and unsorted portion. and we keep repeating process untill we get target in sorted part or start=end (which is only 1 element remains).
        
        while(start<=end){
            int mid=(start+end)/2;

            if(a[mid]==target) return mid;
            if(a[0]<=a[mid]){    //left sorted
                if(a[0]<=target && target<=a[mid]){
                    end=mid-1;
                }
                else start=mid+1;
            }
            else {   //right sorted
                if(a[mid]<=target && target<=a[end]){
                    start=mid+1;
                }
                else {
                    end=mid-1;
                }
            }
        }//while ends here
return -1;
       
    }

};
