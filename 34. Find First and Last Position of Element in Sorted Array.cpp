## Problem Statement ##
## 34. Find First and Last Position of Element in Sorted Array
## https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

############################################### Code begins here ##############################################################

//find first and last occurence using binary search

class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int start=0;
        int end=a.size()-1;
         
        int first=-1;
        int last=-1;
        
        //first occurence
        while(start<=end){
            int mid=(start+end)/2;
            if(a[mid]==target) {end=mid-1;first=mid;}
            else if(target>a[mid]) start=mid+1;
            else end=mid-1;
        }
        if(first==-1) return {-1,-1};

        start=0;
        end=a.size()-1;

        //last occurence
        while(start<=end){
            int mid=(start+end)/2;
            if(a[mid]==target) {start=mid+1;last=mid;}
            else if(target>a[mid]) start=mid+1;
            else end=mid-1;
        }
        return {first,last};
    }
};


