class Solution {
    const long long MOD=1e9+7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> non_zero_count(n + 1, 0), digits;

        for (int i = 0; i < s.size(); i++) {
            non_zero_count[i + 1] = non_zero_count[i];
            if (s[i] != '0') {
                int digit = s[i] - '0';
                non_zero_count[i + 1] = non_zero_count[i] + 1;
                digits.push_back(digit);
            }
        }
        int k = digits.size();
        vector<long long> prefix_sum(k + 1, 0), prefix_val(k + 1, 0),
            power10(k + 1, 1);
        for (int i = 0; i < k; i++) {
            prefix_val[i + 1] = (prefix_val[i] * 10 + digits[i])%MOD;
            prefix_sum[i + 1] = (prefix_sum[i] + digits[i])%MOD;
            power10[i + 1] = (power10[i] * 10)%MOD;
        }
        vector<int> ans;
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int left = non_zero_count[l];
            int right = non_zero_count[r + 1];
            int len = right - left;
            long long x = (prefix_val[right] - ((prefix_val[left] * power10[len])%MOD)+MOD)%MOD;
            long long sum = (prefix_sum[right] - prefix_sum[left]+MOD)%MOD;
            ans.push_back((int)((x * sum)%MOD));
        }
        return ans;
    }
};