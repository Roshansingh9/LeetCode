class Solution {
private:
    int helper(vector<int>& coins, int amount, int index,vector<vector<int>>& dp) {
        if (amount == 0)
            return 1;
        if (amount < 0 || index < 0)
            return 0;

        if(dp[index][amount]!=-1) return dp[index][amount];    
        int not_take = helper(coins, amount, index - 1,dp);
        int take = 0;
        if (coins[index] <= amount) {
            take = helper(coins, amount - coins[index], index,dp);
        }
        return dp[index][amount]=not_take + take;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(coins, amount, n - 1,dp);
    }
};