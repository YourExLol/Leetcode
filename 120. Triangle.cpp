## Problem Statement ##
## 120. Triangle
## https://leetcode.com/problems/triangle/description/

############################################### Code begins here ##############################################################

//simple recursion

class Solution {
public:
    int fn(vector<vector<int>>& a,int i,int j){
        if(i==a.size()) return 0;
        return a[i][j]+min(fn(a,i+1,j),fn(a,i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return fn(triangle,0,0);
    }
};

//Tabulation

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& a) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++) dp[n-1][i]=a[n-1][i];

        //dp[i][j] answer if this was source
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

// Tabulation using 1D array

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& a) {
        int n=a.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++) dp[i]=a[n-1][i];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=a[i][j]+min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};
