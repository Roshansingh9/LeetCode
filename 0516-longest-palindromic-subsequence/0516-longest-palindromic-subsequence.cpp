class Solution {
    private:
    int longestCommonSubsequence(string text1, string text2) {
        int index1 = text1.size();
        int index2 = text2.size();
        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, 0));
        for (int i = 0; i <= index1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= index2; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[index1][index2];
    }
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s2=s;
        reverse(s2.begin(),s2.end());
        int m=longestCommonSubsequence(s,s2);
        return m;
    }
};