#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2, 0);
        unordered_map<int, int> count;
        
        // Count occurrences of each number
        for (int num : nums)
            count[num]++;
        
        // Find repeating and missing numbers
        for (int i = 1; i <= nums.size(); ++i) {
            if (count[i] == 2) // Repeating number
                result[0] = i;
            else if (count[i] == 0) // Missing number
                result[1] = i;
        }
        
        return result;
    }
};
