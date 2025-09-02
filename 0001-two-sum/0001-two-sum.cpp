class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int comp = target - nums[i];
            if (mpp.find(comp) != mpp.end()) {
                return {mpp[comp], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};