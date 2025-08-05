class Solution {


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
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }

        if (nums[0] <= k)
            dp[0][nums[0]] = true;

        for(int index=1;index<n;index++){
            for(int target=1;target<=k;target++){
                bool not_take=dp[index-1][target];
                bool take=false;
                if(nums[index]<=target){
                    take=dp[index-1][target-nums[index]];
                }
                dp[index][target]=not_take || take;
            }
        }    
        return dp[n-1][k];
    }
};