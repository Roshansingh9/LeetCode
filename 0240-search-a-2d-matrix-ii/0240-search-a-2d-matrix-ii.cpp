class Solution {
public:
    bool binarysearch(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (high >= low) {
            int mid = (high + low) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            if (binarysearch(matrix[i], target))
                return true;
        }
        return false;
    }
};