class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int max_time = 0;
        int vis[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 1;
                }
            }
        }
        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        while (!q.empty()) {
            int t = q.front().second;
            int r = q.front().first.first;
            int c = q.front().first.second;
            max_time = max(max_time, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < n && nr >= 0 && nc < m && nc >= 0 &&
                    vis[nr][nc] != 2 && grid[nr][nc] == 1) {
                    q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return max_time;
    }
};