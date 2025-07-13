class Solution {
private:
    void solution(vector<vector<int>>& ans, vector<int> nums, vector<int>& sub,
                  int ind) {
        ans.push_back(sub);
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i-1])
                continue;
            sub.push_back(nums[i]);
            solution(ans, nums, sub, i + 1);
            sub.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        solution(ans, nums, sub, 0);
        return ans;
    }
};