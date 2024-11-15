## Problem Statement ##
## 239. Sliding Window Maximum
## https://leetcode.com/problems/sliding-window-maximum/

############################################### Code begins here ##############################################################

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {

        //we need to find max for every k window, which can be achieved through max heap
        //the only issue is we cant remove any element even if we knew any key.
        //since we need to remove any element stored which is before i-k index.
        //since we are pushing pq.top() any index before i-k index creates problem when its on top.
        //so we only push when pq.top index is >i-k else we pop top till required condition is met.
        priority_queue<pair<int,int>> pq;
        vector<int> v;

        for(int i=0;i<k;i++)
            pq.push({a[i],i});

        v.push_back(pq.top().first);

        for(int i=k;i<a.size();i++){
         pq.push({a[i],i});    

                while(true){
                    if(pq.top().second>i-k){
                        v.push_back(pq.top().first);
                        break;
                    }
                    else  pq.pop();
                }
        }//for loop ends here

        return v;
    }//fn ends here

};
