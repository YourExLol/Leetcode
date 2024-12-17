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

class Solution {
public:

    //S~O(MxN) Soln
    int longestCommonSubsequence(string text1, string text2) {
        int s1=text1.size(),s2=text2.size();
        vector<vector<int>> dp(s1+1,vector<int>(s2+1,0));

        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[s1][s2];       
    }//fn ends here

};

##################################################### Tabulation Space=2xN #################################################
// C++ program to find the longest common subsequence of two strings
// using space optimization

int lcs(string& s1, string& s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
              
                // Characters match, increment LCS length
                cur[j] = 1 + prev[j - 1];
            }
            else
                // Characters don't match, consider the
                  // maximum from above or left
                cur[j] = max(prev[j], cur[j - 1]);
        }
      
        // Update the previous row with the current row
        prev = cur;
    }
  
    // Return the length of the Longest Common Subsequence
    return prev[m];
}

##################################################### Tabulation Space=O(n) ###############################################

//Tabulation Space=1xN

int LCS(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    vector<int> dp(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        int prev = 0; // To store dp[j-1] from the previous row
        for (int j = 1; j <= m; j++) {
            int temp = dp[j]; // Save the current dp[j] before updating it
            if (text1[i - 1] == text2[j - 1])
                dp[j] = prev + 1;
            else 
                dp[j] = max(dp[j], dp[j - 1]); 
            prev = temp; // Update prev to the old dp[j] value
        }
    }

    return dp[m];
}
