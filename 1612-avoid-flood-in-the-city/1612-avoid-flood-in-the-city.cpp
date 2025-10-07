class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> full;
        set<int> dryDays;
        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                int lake = rains[i];
                ans[i] = -1;
                if (full.count(lake)) {
                    int prevDay = full[lake];
                    auto it = dryDays.lower_bound(prevDay);
                    if (it == dryDays.end()) return {};
                    int dryIndex = *it;
                    ans[dryIndex] = lake;
                    dryDays.erase(it);
                }
                full[lake] = i;
            } else {
                dryDays.insert(i);
            }
        }
        return ans;
    }
};
