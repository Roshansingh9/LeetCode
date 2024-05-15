class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int el;
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                el = nums[i];
                count++;
            } else if (el == nums[i])
                count++;
            else
                count--;
        }
        // checking
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el)
                cnt++;
        }
        if (2 * cnt > n) {
            return el;
        }
        return -1;
    }
};