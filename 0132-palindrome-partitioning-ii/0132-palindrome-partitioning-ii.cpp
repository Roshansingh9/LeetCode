class Solution {
private:

    bool ispal(string& s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int helper(string& s, int i,vector<int>& dp) {
        if (i == s.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        int mini = INT_MAX;
        for (int j = i; j < s.size(); j++) {
           
            if (ispal(s,i,j)) {
                int cost = 1 + helper(s,j + 1,dp);
                mini = min(mini, cost);
            }
        }

        return dp[i]=mini;
    }

public:
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
         return helper(s, 0,dp)-1; }
};