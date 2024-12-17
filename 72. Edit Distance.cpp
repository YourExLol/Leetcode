## Problem Statement ##
## 72. Edit Distance
## https://leetcode.com/problems/edit-distance/

############################################### Code begins here #############################################################

// Memoization

int ed(string s1,string s2,int m,int n,vector<vector<int>> &dp){

        if(m==0) return dp[m][n]=n;
        if(n==0) return dp[m][n]=m;
        if(dp[m][n]!=-1) return dp[m][n];

        if(s1[m-1]==s2[n-1]) dp[m][n]=ed(s1,s2,m-1,n-1,dp);
        else dp[m][n]=1+min(ed(s1,s2,m-1,n,dp),min(ed(s1,s2,m,n-1,dp),ed(s1,s2,m-1,n-1,dp)));
        return dp[m][n];
    }

// Tabulation 

int tab(string s1,string s2,int m,int n,vector<vector<int>> &dp){
        for(int i=0;i<n+1;i++) dp[0][i]=i;
        for(int i=0;i<m+1;i++) dp[i][0]=i;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
        return dp[m][n];
        
    }

// Main Fn

    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return ed(word1,word2,m,n,dp); // For Memoization
        return tab(word1,word2,m,n,dp); // For tabulation
    }
