class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            if (num % 2 == 0) {
                freqMap[num]++;
            }
        }

        if (freqMap.empty()) {
            return -1;
        }

        int maxFreq = 0;
        int mostFrequentEvenNum = INT_MAX;
        for (const auto& entry : freqMap) {
            if (entry.second > maxFreq || (entry.second == maxFreq && entry.first < mostFrequentEvenNum)) {
                maxFreq = entry.second;
                mostFrequentEvenNum = entry.first;
            }
        }

        return mostFrequentEvenNum;
    }
};