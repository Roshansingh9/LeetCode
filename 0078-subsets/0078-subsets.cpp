class Solution {
private:
    void solution(vector<int>& nums, vector<vector<int>>& ans,
                  vector<int>& subarray, int i, int size) {
        if (i >= size) {
            ans.push_back(subarray);
            return;
        }
        solution(nums, ans, subarray, i + 1, size);
        subarray.push_back(nums[i]);
        solution(nums, ans, subarray, i + 1, size);
        subarray.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subarray;
        solution(nums, ans, subarray, 0, n);
        return ans;
    }
};