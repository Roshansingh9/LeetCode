class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > far)
                return false;
            far = max(far, i + nums[i]);
            if (far >= n - 1)
                return true;
        }
        return false;
    }
};