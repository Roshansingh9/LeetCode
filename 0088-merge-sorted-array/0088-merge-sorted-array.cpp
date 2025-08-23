class Solution {
private:
    void merge_helper(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m) {
            temp.push_back(nums1[i++]);
        }
        while (j < n) {
            temp.push_back(nums2[j++]);
        }
        for (int k = 0; k < m + n; k++) {
            nums1[k] = temp[k];
        }
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        if (m == 0) { 
            for (int i = 0; i < n; i++)
                nums1[i] = nums2[i];
            return;
        }
        merge_helper(nums1, m, nums2, n);
    }
};