class Solution {
private:
    int helper(int index, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(index == prices.size() || cap == 0) return 0;  // Added cap==0 base case

        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];

        int profit = 0;
        if(buy) {
            profit = max(
                -prices[index] + helper(index + 1, 0, cap, prices, dp),
                helper(index + 1, 1, cap, prices, dp)
            );
        } else {
            profit = max(
                prices[index] + helper(index + 1, 1, cap - 1, prices, dp),
                helper(index + 1, 0, cap, prices, dp)
            );
        }

        return dp[index][buy][cap] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 1, 2, prices, dp);
    }
};
