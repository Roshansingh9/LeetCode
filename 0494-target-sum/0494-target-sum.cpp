class Solution {
private:
    int helper(vector<int>& nums, int target, int index,
               vector<vector<int>>& dp) {
        if (index == 0) {
            if (nums[0] == 0 && target == 0)
                return 2;
            if (nums[0] == target || target == 0)
                return 1;
            return 0;
        }
        if (dp[index][target] != -1)
            return dp[index][target];
        int not_take = helper(nums, target, index - 1,dp);
        int take = 0;
        if (nums[index] <= target) {
            take = helper(nums, target - nums[index], index - 1,dp);
        }
        return dp[index][target] = take + not_take;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int k = target + sum;
        if (k % 2 == 1 || k < 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(k / 2 + 1, -1));
        return helper(nums, k / 2, n - 1, dp);
    }
};