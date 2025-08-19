class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n, vector<int>(m, 1e7));
        effort[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});

        int dx[] = {-1, +1, 0, 0};
        int dy[] = {0, 0, +1, -1};
        while (!pq.empty()) {
            int eff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int nextEffort =
                        max(eff, abs(heights[nr][nc] - heights[r][c]));
                    if (nextEffort < effort[nr][nc]) {
                        effort[nr][nc] = nextEffort;
                        pq.push({nextEffort, {nr, nc}});
                    }
                }
            }
        }
        return effort[n - 1][m - 1] == 1e7 ? -1 : effort[n - 1][m - 1];
    }
};