322. Coin Change
https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150

_______________________________________________________________________________________________________

  ----- Recursion -----------------
  
class Solution {
public:
    int fn(vector<int>& coins, int amount,int n){
        if(amount==0) return 0;
        int res=INT_MAX;
        for(int i=n;i>=0;i--){
            if(amount>=coins[i]){
                int temp=fn(coins,amount-coins[i],n);
                if(temp!=INT_MAX)
                    res=min(res,1+temp);
            }
        }
        return res;
    }
    int coinChange(vector<int>& coins, int amount) {   
        //combination Question// Using for loops
        int n=coins.size();
        int ans=fn(coins,amount,n-1);
        return (ans==INT_MAX)?-1:ans;
    }
};


------ Memoization ----------------------------

  class Solution {
public:
    int fn(vector<int>& coins, int amount,int n,vector<int> &memo){
        if(memo[amount]!=-1) return memo[amount];
        if(amount==0) return memo[0]=0;

        int res=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(amount>=coins[i]){
                int temp=fn(coins,amount-coins[i],n,memo);
                if(temp!=INT_MAX)
                    res=min(res,1+temp);
            }
        }
        return memo[amount]=res;
    }
    int coinChange(vector<int>& coins, int amount) {   
        //combination Question// Using for loops
        int n=coins.size();
        vector<int> memo(amount+1,-1);

        fn(coins,amount,n,memo);
        return ((memo[amount]==INT_MAX))?-1:memo[amount];
    }
};

----------- Tabulation --------------------

  class Solution {
public:
   
    int coinChange(vector<int>& coins, int amount) {   
        //combination Question// Using for loops
        int n=coins.size();
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(i>=coins[j] && dp[i-coins[j]]!=INT_MAX)
                dp[i]=min(1+dp[i-coins[j]],dp[i]);
            }
        }

        return ((dp[amount]==INT_MAX))?-1:dp[amount];
    }
};
