class Solution {
    void combination(vector<int>& candidates, int target, vector<int> currcomb,
                     int currsum,int currindex, vector<vector<int>>& ans) {
        if (currsum > target)
            return;
        if (currsum == target) {
            ans.push_back(currcomb);
            return;
        }
        for (int i = currindex; i < candidates.size(); i++) {
            currcomb.push_back(candidates[i]);
            currsum += candidates[i];
            combination(candidates, target, currcomb, currsum,i, ans);
            currcomb.pop_back();
            currsum-=candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currcomb;
        combination(candidates, target, currcomb, 0,0, ans);
        return ans;
    }
};