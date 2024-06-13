#include <vector>
#include <algorithm>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int totalMoves = 0;
        
        for (size_t i = 0; i < seats.size(); ++i) {
            totalMoves += abs(seats[i] - students[i]);
        }
        
        return totalMoves;
    }
};
