class Solution {
public:
    static const int LOG = 18;

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        // {value, original index}
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = {nums[i], i};

        sort(arr.begin(), arr.end());

        // original index -> sorted position
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // up[j][i] = farthest index reachable after 2^j jumps
        vector<vector<int>> up(LOG, vector<int>(n));

        // Sliding window to compute one jump
        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right + 1 < n &&
                   arr[right + 1].first - arr[left].first <= maxDiff)
                right++;

            up[0][left] = right;
        }

        // Binary lifting table
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u > v)
                swap(u, v);

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (up[LOG - 1][u] < v) {
                ans.push_back(-1);
                continue;
            }

            int jumps = 0;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] < v) {
                    jumps += (1 << j);
                    u = up[j][u];
                }
            }

            ans.push_back(jumps + 1);
        }

        return ans;
    }
};