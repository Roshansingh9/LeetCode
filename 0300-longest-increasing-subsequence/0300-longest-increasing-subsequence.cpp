class Solution {
private:
    int helper(int index, int prev_index, vector<int>& nums,
               vector<vector<int>>& dp) {

        if (index == nums.size())
            return 0;

        if (prev_index != -1) {
            if (dp[index][prev_index+1] != -1)
                return dp[index][prev_index+1];
        }
        int not_take = helper(index + 1, prev_index, nums, dp);
        int take = INT_MIN;
        if (prev_index == -1 || nums[index] > nums[prev_index]) {
            take = helper(index + 1, index, nums, dp) + 1;
        }
        return dp[index][prev_index+1] = max(take, not_take);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n+1, -1));
        return helper(0, -1, nums, dp);
    }
};