## Problem Statement ##
## 347. Top K Frequent Elements
## https://leetcode.com/problems/top-k-frequent-elements/description/

############################################### Code begins here ##############################################################

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> um;

      //use map for frequency  and max heap for k top elements
    for(auto x:nums) um[x]++;           
    priority_queue<pair<int,int>> pq;

    for(auto [x,y]:um){
        pq.push({y,x});
    }      

    vector<int> ans;

    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }                                    
        return ans;
    }//fn ends here
};
