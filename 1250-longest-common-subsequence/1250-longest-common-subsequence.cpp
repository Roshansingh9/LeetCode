class Solution {
private:
    int helper(int index1, int index2, string& text1, string& text2,vector<vector<int>>& dp) {
        if (index1 < 0 || index2 < 0)
            return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if (text1[index1] == text2[index2]) {
            return dp[index1][index2]=1 + helper(index1 - 1, index2 - 1, text1, text2,dp);
        } else {
          return dp[index1][index2]=max(helper(index1 - 1, index2, text1, text2,dp),
                            helper(index1, index2 - 1, text1, text2,dp));
        }
        
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int index1 = text1.size();
        int index2 = text2.size();
        vector<vector<int>>dp(index1+1,vector<int>(index2+1,-1));
        return helper(index1-1, index2-1, text1, text2,dp);
    }
};