class Solution {
private:
    int helper(vector<int>& coins, int amount, int index,vector<vector<int>>& dp) {
        if (index == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9; 
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int not_take = helper(coins, amount, index - 1,dp);
        int take = 1e9;
        if (coins[index] <= amount)
            take = 1 + helper(coins, amount - coins[index], index,dp);

        return dp[index][amount]=min(take,not_take);     
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
         int ans = helper(coins, amount, n - 1,dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};