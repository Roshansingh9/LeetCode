class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      unordered_map<int, int> count_map;
        int odd_count = 0;
        int result = 0;
        
        count_map[0] = 1;

        for (int num : nums) {
            if (num % 2 == 1) {
                odd_count++;
            }

            if (count_map.find(odd_count - k) != count_map.end()) {
                result += count_map[odd_count - k];
            }

            count_map[odd_count]++;
        }

        return result;   
    }
};