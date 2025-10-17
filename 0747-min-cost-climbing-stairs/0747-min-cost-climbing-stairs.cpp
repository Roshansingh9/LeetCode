class Solution {
    private:
    int helper(vector<int>& cost,int n,int i,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int result=min(helper(cost,n,i+1,dp),helper(cost,n,i+2,dp))+cost[i];
        return dp[i]=result;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(helper(cost,n,0,dp),helper(cost,n,1,dp));
    }
};