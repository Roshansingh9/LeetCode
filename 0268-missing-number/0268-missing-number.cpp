class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1;
        if (nums[0] != 0)
            return 0;
        for (i; i < nums.size(); i++) {
            if (nums[i - 1] + 1 != nums[i])
                return nums[i - 1] + 1;
        }
        return nums[i - 1] + 1;
    }
};