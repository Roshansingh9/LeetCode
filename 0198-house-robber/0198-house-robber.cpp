class Solution {
    private:
    int solution(int index,vector<int>& nums,vector<int>& dp){
        if(index>=nums.size()) return 0;
        
        if(dp[index]!=-1) return dp[index];
        int take=solution(index+2,nums,dp)+nums[index];
        int not_take=solution(index+1,nums,dp);
        
        return dp[index]=max(take,not_take);
        

    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solution(0,nums,dp);
    }
};