class Solution {
private:
    int helper(vector<int>& arr, int k, int index, int n, vector<int>& dp) {
        if (index == n)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int len = 0, max_element = INT_MIN, sum = 0;
        for (int i = index; i < min(n, index + k); i++) {
            len++;
            max_element = max(max_element, arr[i]);
            int cost = max_element * len + helper(arr, k, i + 1, n, dp);
            sum = max(sum, cost);
        }
        return dp[index] = sum;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return helper(arr, k, 0, n, dp);
    }
};
