class Solution {
    private:
    int solution(int n,vector<int>& dp){
        if(n==0 || n==1) return 1;
        int ans;
        if(dp[n]!=-1) return dp[n];
        if(n>1){
             dp[n]=solution(n-1,dp)+solution(n-2,dp);
        }
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
       return solution(n,dp); 
    }
};