class Solution {
    private:
    int helper(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        int n=matrix.size();
        if (j < 0 || j >= n) return INT_MAX;

       
        if (i == n - 1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int up=helper(matrix,i+1,j+1,dp);
        int left=helper(matrix,i+1,j,dp);
        int right=helper(matrix,i+1,j-1,dp);
        return dp[i][j]=min(up,min(left,right))+matrix[i][j];
    }
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int minsum=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            minsum=min(minsum,helper(matrix,0,i,dp));
        }
      return minsum;  
    }
};