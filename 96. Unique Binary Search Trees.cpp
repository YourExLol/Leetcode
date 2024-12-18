## Problem Statement ##
## 96. Unique Binary Search Trees
## https://leetcode.com/problems/unique-binary-search-trees/

############################################### Code begins here ##############################################################

#################### Recursion #################################################

int numTreesRec(int n) {
        // Your code here
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
  
        int ans=0;
  
        for(int i=1;i<=n;i++) 
        ans+=numTrees(i-1)*numTrees(n-i);
        return ans;
    }

#################### Memoization ################################################

int fn(int n,vector<int> &memo){
        //base case
        if(memo[n]!=-1) return memo[n];
        if(n==0 || n==1) return memo[n]=1;
        
        int ans=0;
        
        for(int i=1;i<=n;i++)
        ans+=fn(i-1,memo)*fn(n-i,memo);
  
        return memo[n]=ans;
    }
//Refer main fn
#################### Tabulation #################################################

int tab(int n,vector<int> &dp){
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
           int ans=0;
            for(int j=1;j<=i;j++)
                ans+=dp[j-1]*dp[i-j]; //i is n
            dp[i]=ans;
        }    
  
        return dp[n];
    }

################### Main Function ################################################

int numTrees(int n) {
        // Your code here
  //for Memoization
        vector<int> memo(n+1,-1); 
        return fn(n,memo);
  //for Tabulation
        vector<int> dp(n+1,-1);
        return tab(n,dp);
       
    }
