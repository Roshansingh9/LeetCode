class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& q) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> gcd(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            gcd[i] = freq[i];
            for (int j = 2 * i; j <= mx; j += i) {
                gcd[i] += freq[j];
            }
        }

        for (int i = 1; i <= mx; i++) {
            gcd[i] = gcd[i] * (gcd[i] - 1) / 2;
        }

        for (int i = mx; i >= 1; i--) {
            for (int j = 2 * i; j <= mx; j += i) {
                gcd[i] -= gcd[j];
            }
        }

        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            pref[i] += pref[i - 1] + gcd[i];
        }

        vector<int> ans;
        for (int i = 0; i < q.size(); i++) {
            long long qu = q[i];
            ans.push_back(lower_bound(pref.begin(), pref.end(), qu + 1) -
                          pref.begin());
        }
        return ans;
    }
};