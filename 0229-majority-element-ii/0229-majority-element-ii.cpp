class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candi1 = 0, candi2 = 1; 
        int count1 = 0, count2 = 0;

        
        for (int num : nums) {
            if (num == candi1) {
                count1++;
            } else if (num == candi2) {
                count2++;
            } else if (count1 == 0) {
                candi1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candi2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candi1) count1++;
            else if (num == candi2) count2++;
        }

        vector<int> ans;
        if (count1 > n / 3) ans.push_back(candi1);
        if (count2 > n / 3) ans.push_back(candi2);

        return ans;
    }
};
