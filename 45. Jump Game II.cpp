45. Jump Game II
https://leetcode.com/problems/jump-game-ii/

////////////////////////

-----------------Memoization--------------------------

  int fn(int s,vector<int> &a,int &n,vector<int> &memo){
        if(memo[s]!=-1) return memo[s];
        if(s>=n-1) return 0;

        int res=INT_MAX/10;
        for(int i=s+1;i<=s+a[s] && i<n;i++){
            res=min(res,fn(i,a,n,memo));
        }
        return memo[s]=1+res;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> memo(n,-1);

        return fn(0,nums,n,memo);
        
    }


-----------------Tabulation----------------------------------

  int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(j+nums[j]>=i && nums[j]!=INT_MAX)
                    dp[i]=min(dp[i],1+dp[j]);
            }
        }
        return dp[n-1];
    }


//Greedy

int minJumps(vector<int>& arr) {
      int n = arr.size();

    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;

    // Stores the maximal reachable index
    int maxReach = 0;

    // stores the number of steps  we can still take
    int currReach = 0;

    // stores the number of jumps needed 
      // to reach current reachable index
    int jump = 0;

    // Start traversing array
    for (int i = 0; i < n; i++) {
          maxReach = max(maxReach, i+arr[i]);
      
          // If we can reach last index by jumping 
          // from current position return Jump + 1
          if (maxReach >= n-1) {
              return jump + 1;
        }
      
          // Increment the Jump as we reached the 
          // Current Reachable index
          if (i == currReach) {      // have to make the jump
          
              // If Max reach is same as current index
              // then we can not jump further
              if (i == maxReach) {      // means any step in range i+arr[i] was not taking you to more than start+arr[start]
                  return -1;
              }
          
              // If Max reach > current index then increment 
              // jump and update current reachable index 
              else {
                jump++;    
                currReach = maxReach;
            }
        }
    }
  
    return -1;
}
