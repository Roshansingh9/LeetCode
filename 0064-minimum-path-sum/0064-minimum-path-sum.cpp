class Solution {
    private:
    int helper(vector<vector<int>>& grid,int n,int m,int i,int j,vector<vector<int>>& dp){
      if(i==n-1 && j==m-1){
        return grid[i][j];
      }
      if(i>=n || j>=m){
        return INT_MAX;
      }
      if(dp[i][j]!=-1){
        return dp[i][j];
      }
      long long left=(long long)grid[i][j]+helper(grid,n,m,i,j+1,dp);
      long long down=(long long)grid[i][j]+helper(grid,n,m,i+1,j,dp);
      return dp[i][j]=(int)min(left,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(grid,n,m,0,0,dp);
    }
};


/*    0   1   2
0   1   3   1
1   1   5   1
2   4   2   1

(0,0)--(0,1)--(0,2) or (1,1)
        (1,0)--(1,1) or (2,1)*/