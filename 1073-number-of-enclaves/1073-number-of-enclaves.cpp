class Solution {

private:
    void dfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int row,
             int col) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1, 0, 0, +1};
        int dy[] = {0, -1, +1, 0};

        for (int i = 0; i < 4; i++) {
            int n_row = row + dx[i];
            int n_col = col + dy[i];
            if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m &&
                grid[n_row][n_col] == 1 && !vis[n_row][n_col]) {
                dfs(vis, grid, n_row, n_col);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !vis[0][i])
                dfs(vis, grid, 0, i);
            if (grid[n - 1][i] == 1 && !vis[n - 1][i])
                dfs(vis, grid, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0])
                dfs(vis, grid, i, 0);
            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
                dfs(vis, grid, i, m - 1);
        }
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;
            }
        }
        return count;
    }
};