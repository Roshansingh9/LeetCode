class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0)
            return 0;
        int n = heightMap[0].size();
        if (n == 0)
            return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            minHeap;

        for (int i = 0; i < m; i++) {
            minHeap.push({heightMap[i][0], {i, 0}});
            minHeap.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; j++) {
            minHeap.push({heightMap[0][j], {0, j}});
            minHeap.push({heightMap[m - 1][j], {m - 1, j}});
            visited[0][j] = visited[m - 1][j] = true;
        }

        int water = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!minHeap.empty()) {
            auto [height, pos] = minHeap.top();
            minHeap.pop();
            int x = pos.first, y = pos.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k], ny = y + dirs[k + 1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
                    continue;
                visited[nx][ny] = true;
                water += max(0, height - heightMap[nx][ny]);
                minHeap.push({max(height, heightMap[nx][ny]), {nx, ny}});
            }
        }

        return water;
    }
};