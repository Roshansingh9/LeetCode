class Solution {
private:
    bool helper(vector<int>& nums, int index, int target,vector<vector<int>>& dp) {
        if (target == 0)
            return true;

        if (index == 0)
            return target == nums[index];
        if(dp[index][target]!=-1) return dp[index][target];
        bool not_take = helper(nums, index -1, target,dp);
        bool take=false;
        if(nums[index]<=target){
            take=helper(nums,index-1,target-nums[index],dp);
        }
        return dp[index][target]=take || not_take;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, k;
       
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        } else {
            k = sum / 2;
        }
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return helper(nums, n - 1, k,dp);
    }
};