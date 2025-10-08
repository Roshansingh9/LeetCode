class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;

        for (auto s : spells) {
            long long minPotion = (success + s - 1) / s;
            int l = 0, r = m;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (potions[mid] >= minPotion) r = mid;
                else l = mid + 1;
            }
            ans.push_back(m - l); 
        }
        return ans;
    }
};