class Solution {
    private:
    int helper(vector<int>& nums,int i,int j,vector<vector<int>>& dp){
        if(i>j) return 0;
        int maxi=INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind=i;ind<=j;ind++){
            int cost=nums[i-1]*nums[ind]*nums[j+1]+helper(nums,i,ind-1,dp)+helper(nums,ind+1,j,dp);
            maxi=max(cost,maxi);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(nums,1,n-2,dp);
    }
};