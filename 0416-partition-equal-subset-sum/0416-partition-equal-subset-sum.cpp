class Solution {
private:
    bool helper(vector<int>& nums, int n, int target, vector<vector<int>>& dp) {
        
        if (target == 0) return true;     
        if (n == 0) return nums[0] == target;


        if (dp[n][target] != -1) return dp[n][target];

    
        bool not_take = helper(nums, n - 1, target, dp);

    
        bool take = false;
        if (nums[n] <= target)
            take = helper(nums, n - 1, target - nums[n], dp);

        return dp[n][target] = take || not_take;
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false; 

        int target = total / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return helper(nums, n - 1, target, dp);
    }
};
