
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int maxElt = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxElt + 1, 0);
        vector<int> res;

        
        for (int n : nums)
            freq[n]++;

       
        for (int i = 0; i <= maxElt; ++i) {
            if (freq[i] == 2)
                res.push_back(i);
        }

        return res;
    }
};