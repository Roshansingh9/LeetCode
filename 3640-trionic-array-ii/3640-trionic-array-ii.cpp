class Solution {
public:
    static long long maxSumTrionic(vector<int>& nums) {
        const int n = nums.size();

        long long ans = -1e15;
        for (int i = 0, l = 0, p = 0, q = 0, r = 0; i < n - 1; i += i == l) {

            while (i < n - 1 && nums[i] >= nums[i + 1])
                i++;
            l = i;

            long long Sum = 0;

            while (i < n - 1 && nums[i] < nums[i + 1]) {
                Sum += (nums[i] > 0) ? nums[i] : 0;
                i++;
            }
            p = i;
            if (p == l || (p + 1 < n && nums[p] == nums[p + 1]))
                continue;

            Sum += (nums[p - 1] < 0) ? nums[p - 1] : 0;

            while (i < n - 1 && nums[i] > nums[i + 1]) {
                Sum += nums[i];
                i++;
            }
            q = i;
            if (p == q || (q + 1 < n && nums[q] == nums[q + 1]))
                continue;

            Sum += nums[q];
            long long incr = 0, maxIncr = INT_MIN;

            while (i < n - 1 && nums[i] < nums[i + 1]) {
                incr += nums[i + 1];
                maxIncr = max(maxIncr, incr);
                i++;
            }
            r = i;

            if (r > q) {
                ans = max(ans, Sum + maxIncr);

                i = q;
            }
        }
        return ans;
    }
};