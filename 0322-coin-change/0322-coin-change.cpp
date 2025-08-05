class Solution {
private:
    int helper(vector<int>& coins, int amount, int index,
               vector<vector<int>>& dp) {
        if (index == 0) {
            if (amount % coins[index] == 0) {
                return amount / coins[index];
            } else {
                return 1e7;
            }
        }
        if (dp[index][amount] != -1 )
            return dp[index][amount];
        int not_take = helper(coins, amount, index - 1, dp);
        int take = 1e7;
        if (coins[index] <= amount) {
            take = 1 + helper(coins, amount - coins[index], index, dp);
        }
        return dp[index][amount] = min(take, not_take);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(coins, amount, n - 1, dp);
        if (ans >= 1e7) {
            return -1;
        }
        return ans;
    }
};