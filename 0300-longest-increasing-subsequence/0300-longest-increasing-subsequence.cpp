class Solution {
private:
    int helper(vector<int>& nums, int prev, int curr, int size,vector<vector<int>>& dp) {
        if (curr == size) {
            return 0;
        }
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }
        int not_take = helper(nums, prev, curr + 1, size,dp);
        int take = INT_MIN;
        if (prev == -1 || nums[curr] > nums[prev]) {
            take = helper(nums, curr, curr + 1, size,dp)+1;
        }
        return dp[prev+1][curr]=max(take, not_take);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return helper(nums, -1, 0, n,dp);
    }
};