790. Domino and Tromino Tiling

----------------------- Recursion --------------------------------

  class Solution {
public:
    int fn(int j,int n,bool pregap){
        if(j>n || (j==n && pregap)) return 0;
        if(j==n && !pregap) return 1;
        if(pregap)
            return fn(j+1,n,false)+fn(j+1,n,true);
        return fn(j+2,n,false)+fn(j+1,n,false)+2*fn(j+2,n,true);

    }

    int numTilings(int n) {
        return fn(0,n,false);
    }
};

------------------------ Memoization ----------------------------------------
// Let me explain what dp[r][j] represents in this problem in more detail:
// dp[r][j] represents the number of ways to tile a board from column j to the end (column n-1), given a specific state at column j.
// The r value (0 or 1) indicates the state of the current position:

// r = 0 (when pregap = false): This means there is no "gap" at the current position. Both cells in column j are available to be tiled.
// r = 1 (when pregap = true): This means there is already a "gap" or extension from a previous tiling that covers the top cell in column j. In other words, only the bottom cell in column j is available to be tiled.
const int mod=1e9+7;
class Solution {
public:
    long fn(int j,int n,bool pregap,vector<vector<int>> &memo){
        if(j>n) return 0;
        if(memo[pregap][j]!=-1) return memo[pregap][j];

        if(pregap)
            return memo[pregap][j]=(fn(j+1,n,false,memo)+fn(j+1,n,true,memo))%mod;
        return memo[pregap][j]=(fn(j+2,n,false,memo)+fn(j+1,n,false,memo)+2*fn(j+2,n,true,memo))%mod;

    }

    int numTilings(int n) {
        vector<vector<int>> memo(2,vector<int>(n+1,-1));
        memo[0][n]=1;
        memo[1][n]=0;
        return fn(0,n,false,memo);
    }
};

-----------------------------Tabulation--------------------------------------

  const int mod=1e9+7;
class Solution {
public:

    long long fn(int n){
        vector<vector<long long>> dp(2,vector<long long>(n+1,0));
        dp[0][n]=1;
        dp[1][n]=0;

        for(int j=n-1;j>=0;j--){
            dp[1][j]=(dp[0][j+1]+dp[1][j+1])%mod;
            if(j+2>n) dp[0][j]=dp[0][j+1]%mod;
            else dp[0][j]=(dp[0][j+2]+dp[0][j+1]+2*dp[1][j+2])%mod;
        }
        return dp[0][0];
    }
    int numTilings(int n) {
        return fn(n);
    }
};
