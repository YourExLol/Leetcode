## Problem Statement ##
## 871. Minimum Number of Refueling Stops
## https://leetcode.com/problems/minimum-number-of-refueling-stops/
## https://www.geeksforgeeks.org/minimize-refills-to-reach-end-of-path/

############################################### Code begins here ##############################################################

class Solution {
public:
    int minRefuelStops(int target, int starFuel, vector<vector<int>>& stations) {
       
       //My solution
        if(target<=starFuel) return 0;
        else if(stations.size()==0 || stations[0][0]>starFuel) return -1;

        int ans=0,curr_dist=starFuel,index=1;
        priority_queue<int> pq;
        pq.push(stations[0][1]);

        while(!pq.empty() && curr_dist<target && index<stations.size()){
            while(curr_dist<stations[index][0] && !pq.empty()){
                curr_dist+=pq.top();
                pq.pop();
                ans++;
            }

            // if(curr_dist<target && pq.empty()==1) {cout<<"Exit Index: "<<index<<endl;
            // return -1;}
            if(curr_dist>=stations[index][0])
            {pq.push(stations[index][1]);
            index++;}
        }

        if(index>=stations.size()) {
            while(curr_dist<target && !pq.empty()){
                curr_dist+=pq.top();
                pq.pop();
                ans++;
            }
        }
        
        if(curr_dist<target) return -1;
        else return ans;


        // less line solution //logic is same

         // If starting fuel is already greater or equal to target, no need to 
        // refuel
        if (startFuel >= target) return 0;

        // Create a max heap to store the fuel capacities of stations
        priority_queue<int> max_heap;
        int i = 0, n = stations.size();
        int stops = 0;
        int max_distance = startFuel;

        // Loop until the car reaches the target or is out of fuel
        while (max_distance < target) {
            // Add fuel to the heap for stations within the current range
            while (i < n && stations[i][0] <= max_distance) {
                max_heap.push(stations[i][1]);
                i++;
            }

            // If there are no more stations in range and we can't reach the target, return -1
            if (max_heap.empty()) return -1;

            // Refuel with the largest amount available and increment stops
            max_distance += max_heap.top();
            max_heap.pop();
            stops++;
        }

        // Return the number of stops taken
        return stops;


    }
};
