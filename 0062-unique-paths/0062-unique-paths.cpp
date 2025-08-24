class Solution {
    private:
    int helper(int m,int n,vector<vector<int>>& dp){
        if(m<0 || n<0) return 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        //up
        int up=helper(m-1,n,dp);
        // left
        int left=helper(m,n-1,dp);
        return dp[m][n]=left+up;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
    }
};