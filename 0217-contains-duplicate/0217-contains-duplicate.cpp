class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mpp.count(nums[i]))
                return true;
            mpp.insert(nums[i]);
        }
        return false;
    }
};