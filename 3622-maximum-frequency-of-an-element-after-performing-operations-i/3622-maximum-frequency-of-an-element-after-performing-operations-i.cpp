
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int n = maxNum + k + 2;
        vector<int> freq(n, 0);

        for (int num : nums) freq[num]++;

        vector<int> prefix(n, 0);
        prefix[0] = freq[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + freq[i];

        int ans = 0;
        for (int t = 0; t < n; t++) {
            if (freq[t] == 0 && numOperations == 0) continue;
            int left = max(0, t - k), right = min(n - 1, t + k);
            int totalInRange = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
            int adjustable = totalInRange - freq[t];
            int newFrequency = freq[t] + min(numOperations, adjustable);
            ans = max(ans, newFrequency);
        }

        return ans;
    }
};
