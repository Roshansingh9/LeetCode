class Solution {
    private:
    int helper(vector<int>& nums,int n,int i,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=helper(nums,n,i+2,dp)+nums[i];
        int not_take=helper(nums,n,i+1,dp);
        return dp[i]=max(take,not_take);
    }
public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      vector<int>dp(n+1,-1);
      return helper(nums,n,0,dp);  
    }
};