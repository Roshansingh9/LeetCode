class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            vector<int>& last = ans.back();
            if (intervals[i][0] <= last[1]) {
                last[1] = max(intervals[i][1], last[1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};