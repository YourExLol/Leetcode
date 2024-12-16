## Problem Statement ##
## 1143. Longest Common Subsequence
## https://leetcode.com/problems/longest-common-subsequence/

############################################### Code begins here ##############################################################

###############################################   Recursive ###################################################################
class Solution {
  public:
    // Function to find the length of the longest common subsequence in two strings.
    
    int LCS(string s1,string s2,int size1,int size2){
        
        if(size1==0 || size2==0) return 0;
        
        if(s1[size1-1]==s2[size2-1]) return 1+LCS(s1,s2,size1-1,size2-1);
        else {
            return max(LCS(s1,s2,size1,size2-1),LCS(s1,s2,size1-1,size2));
        }
        
    }
    int getLCSLength(string& s1, string& s2) {
        
        return LCS(s1,s2,s1.size(),s2.size());
        
        
    }
};

###############################################   Memoization #################################################################
class Solution {
  public:
    // Function to find the length of the longest common subsequence in two strings.
    
    int LCS(string &s1,string &s2,int size1,int size2,vector<vector<int>> &dp){
        
        //answer dp[size1][size2]
        
        //base cases
        if(size1==0 || size2==0) return dp[size1][size2]=0;
        //if already computed
        if(dp[size1][size2]!=-1) return dp[size1][size2];
        //if not computed
        
        if(s1[size1-1]==s2[size2-1]) return dp[size1][size2]=1+LCS(s1,s2,size1-1,size2-1,dp);
        else {
            return dp[size1][size2]=max(LCS(s1,s2,size1,size2-1,dp),LCS(s1,s2,size1-1,size2,dp));
        }
        
    }
    int getLCSLength(string& s1, string& s2) {
       
       int size1=s1.size();
       int size2=s2.size();
       vector<vector<int>> dp(size1+1,vector<int>(size2+1,-1));
       
       return LCS(s1,s2,s1.size(),s2.size(),dp);
        
        
    }
};


################################################## Tabulation Space=MxN #########################################################

//Tabulation Space=2xN

//Tabulation Space=1xN
