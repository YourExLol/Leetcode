52. N-Queens II

  ---------------------------- BackTracking _______________________________--


  class Solution {
public:
    bool clash(vector<vector<int>> &grid,int queen_no,int col,int side){
        for(int i=0;i<queen_no;i++)
            if(grid[i][col]==1)
                return true;
        
        int i=queen_no;
        int j=col;

        while(i>=0 && j<side){
            if(grid[i][j]==1)
                return true;
            i--;
            j++;
        }

        i=queen_no;
        j=col;
        while(i>=0 && j>=0){
            if(grid[i][j]==1)
                return true;
            i--;
            j--;
        }
        return false;
    }

    void fn(vector<vector<int>> &grid,int queen_no,int side,int &ans,vector<bool> &rowC,vector<bool> &leftD,vector<bool> &rightD){

        if(queen_no==side){
            ans+=1;
            return;
        }

        for(int j=0;j<side;j++){
            if(rowC[j] || leftD[queen_no-j+side-1] || rightD[queen_no+j])
                continue;
            
                rowC[j]=true;
                leftD[queen_no-j+side-1]=true;
                rightD[queen_no+j]=true;
                grid[queen_no][j]=1;

                fn(grid,queen_no+1,side,ans,rowC,leftD,rightD);

                grid[queen_no][j]=0;
                rowC[j]=false;
                leftD[queen_no-j+side-1]=false;
                rightD[queen_no+j]=false;
            
        }
    }

    int totalNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        int ans=0;
        vector<bool> rowC(n,false);
        vector<bool> leftD(2*n,false);
        vector<bool> rightD(2*n,false);
        fn(grid,0,n,ans,rowC,leftD,rightD);  
        return ans;
    }


};
