class Solution {
private:
    int helper(string& str1, string& str2, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (str1[i - 1] == str2[j - 1])
            return dp[i][j] = 1 + helper(str1, str2, i - 1, j - 1, dp);
        else
            return dp[i][j] = max(helper(str1, str2, i - 1, j, dp), helper(str1, str2, i, j - 1, dp));
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        helper(str1, str2, n, m, dp);  

        
        int i = n, j = m;
        string ans = "";

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            } else {
                ans += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }
        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
