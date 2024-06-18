#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs(n);

        for (int i = 0; i < n; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());

        sort(worker.begin(), worker.end());

        int maxProfit = 0, res = 0, j = 0;

        for (int ability : worker) {

            while (j < n && ability >= jobs[j].first) {
                maxProfit = max(maxProfit, jobs[j].second);
                ++j;
            }

            res += maxProfit;
        }

        return res;
    }
};
