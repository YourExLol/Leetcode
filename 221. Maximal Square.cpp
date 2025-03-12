221. Maximal Square

______________________________________ Simple Recursion ___________________________

class Solution {
public:
//consider grid[i][j] ending cell of square

    int fn(vector<vector<char>>& matrix,int i,int j,int &ans){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;

        int temp=min({fn(matrix,i+1,j,ans),fn(matrix,i,j+1,ans),fn(matrix,i+1,j+1,ans)});
        if(matrix[i][j]=='0') return 0; //calling this before fn will cause pruning of recusrion paths since thae cell maybe 0 but answer can be found along that path


        int val=1+temp;
        ans=max(ans,val);
        return val;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        int ans=0;
        fn(matrix,0,0,ans);
        return ans*ans;
    }
};

################################### Memoization ###############################################

class Solution {
public:
//consider grid[i][j] ending cell of square

    int fn(vector<vector<char>>& matrix,int i,int j,int &ans,vector<vector<int>> &memo){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];

        int temp=min({fn(matrix,i+1,j,ans,memo),fn(matrix,i,j+1,ans,memo),fn(matrix,i+1,j+1,ans,memo)});
        if(matrix[i][j]=='0') return memo[i][j]=0; //calling this before fn will cause pruning of recusrion paths since thae cell maybe 0 but answer can be found along that path


        memo[i][j]=1+temp;
        ans=max(ans,memo[i][j]);
        return memo[i][j];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> memo(row,vector<int>(col,-1));
        int ans=0;
        fn(matrix,0,0,ans,memo);
        return ans*ans;
    }
};

################################### Tabulation ###############################################

int maxSquare(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    int ans = 0;
    
    // Create 2d array for tabulation
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // Fill the dp 
    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            
            // If square cannot be formed
            if (mat[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            
            dp[i][j] = 1 + min({dp[i][j+1], 
            dp[i+1][j], dp[i+1][j+1]});
            
            ans = max(ans, dp[i][j]);
        }
    }
    
    return ans;
}
