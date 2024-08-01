#include <vector>
#include <string>

class Solution {
public:
    int countSeniors(std::vector<std::string>& details) {
        int seniorCount = 0;
        for (const std::string& info : details) {
            char tens = info[11];
            char ones = info[12];
            if (tens > '6' || (tens == '6' && ones > '0')) {
                seniorCount++;
            }
        }
        return seniorCount;
    }
};
