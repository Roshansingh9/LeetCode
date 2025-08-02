class Solution {
    private:
    int solution(int m,int n,vector<vector<int>>& dp){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0 ) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int left=solution(m,n-1,dp);
        int right=solution(m-1,n,dp);
        return dp[m][n]=left+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solution(m-1,n-1,dp);
    }
};