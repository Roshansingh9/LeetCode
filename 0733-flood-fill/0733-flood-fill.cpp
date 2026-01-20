class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        int startColor = image[sr][sc];
        if (startColor == color) return image;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        q.push({sr, sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !vis[nr][nc] && image[nr][nc] == startColor) {

                    vis[nr][nc] = 1;
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};
