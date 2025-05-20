class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countzero = 0, countone = 0, counttwo = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                countzero++;
            if (nums[i] == 1)
                countone++;
            if (nums[i] == 2)
                counttwo++;
        }
        int k = 0;
        while (countzero != 0) {
            nums[k++] = 0;
            countzero--;
        }
        while (countone != 0) {
            nums[k++] = 1;
            countone--;
        }
        while (counttwo != 0) {
            nums[k++] = 2;
            counttwo--;
        }
    }
};