class Solution {
private:
    void solution(vector<vector<int>>& ans, vector<int>& sub, vector<int>& nums,
                  int target, int index) {
        if (target == 0) {
            ans.push_back(sub);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > target)
                break;
            sub.push_back(nums[i]);
            solution(ans, sub, nums, target - nums[i], i );
            sub.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        solution(ans, sub, candidates, target, 0);

        return ans;
    }
};