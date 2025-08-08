class Solution {
    private:
    int helper(vector<int>& cuts,int i,int j,vector<vector<int>>& dp){
       
         if(i>j) return 0;
         if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e7;
        
        for(int ind=i;ind<=j;ind++){
            int cost=cuts[j+1]-cuts[i-1]+helper(cuts,i,ind-1,dp)+helper(cuts,ind+1,j,dp);
            mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    } 
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int a=cuts.size();
        vector<vector<int>>dp(a,vector<int>(a,-1));
        return helper(cuts,1,a-2,dp);
    }
};