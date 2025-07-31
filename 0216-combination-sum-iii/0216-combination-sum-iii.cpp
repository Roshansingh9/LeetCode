class Solution {
private:
    void solution(vector<vector<int>>& ans, vector<int>& sub, vector<int>& nums,
                  int k, int n, int i) {
        if (n == 0 && sub.size() == k) {
            ans.push_back(sub);
            return;
        }
        if (n < 0 || sub.size() > k || i>nums.size())
            return;
        solution(ans, sub, nums, k, n, i + 1);
        sub.push_back(nums[i]);
        solution(ans, sub, nums, k, n - nums[i], i + 1);
        sub.pop_back();
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> sub;
        solution(ans, sub, nums, k, n, 0);
        return ans;
    }
};