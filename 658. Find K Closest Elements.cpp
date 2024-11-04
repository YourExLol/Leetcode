## Problem Statement ##
## 658. Find K Closest Elements
## https://leetcode.com/problems/find-k-closest-elements/description/

############################################### Code begins here ##############################################################

//Can be done through Binary Search and Priority Queue
//GFG Article https://www.geeksforgeeks.org/find-k-closest-elements-given-value/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<pair<int,int>> s;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            
            s.insert({abs(arr[i]-x),i});
        }
        for(auto [x,y]:s) {
            cout<<x<<" : "<<y<<endl;
        }
        auto it=s.begin();
        while(k--){
            ans.push_back(arr[it->second]);
            it++;

        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
