
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int B = sqrt(n) + 1;
        int blocks = (n + B - 1) / B;

        vector<long long> a(n, 0), sum(blocks, 0);
        vector<long long> sq(blocks, 0);
        vector<int> lazy(blocks, 0), last(100001, -1);

        auto push = [&](int b) {
            if (!lazy[b]) return;

            int l = b * B, r = min(n, l + B);

            for (int i = l; i < r; i++)
                a[i] += lazy[b];

            lazy[b] = 0;
            sum[b] = sq[b] = 0;

            for (int i = l; i < r; i++) {
                sum[b] = (sum[b] + a[i]) % MOD;
                sq[b] = (sq[b] + a[i] * a[i]) % MOD;
            }
        };

        auto update = [&](int l, int r) {
            for (int b = l / B; b <= r / B; b++) {
                int L = b * B, R = min(n, L + B) - 1;

                if (l <= L && R <= r) {
                    sq[b] = (sq[b] + 2 * sum[b] + (R - L + 1)) % MOD;
                    sum[b] = (sum[b] + R - L + 1) % MOD;
                    lazy[b]++;
                } else {
                    push(b);

                    for (int i = max(l, L); i <= min(r, R); i++) {
                        sq[b] = (sq[b] - a[i] * a[i] % MOD + MOD) % MOD;
                        a[i]++;
                        sq[b] = (sq[b] + a[i] * a[i]) % MOD;
                        sum[b] = (sum[b] + 1) % MOD;
                    }
                }
            }
        };

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            update(last[nums[i]] + 1, i);
            last[nums[i]] = i;

            for (int b = 0; b < blocks; b++)
                ans = (ans + sq[b]) % MOD;
        }

        return ans;
    }
};
