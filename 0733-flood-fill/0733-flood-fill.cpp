class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int initial_color = image[sr][sc];
        if (image[sr][sc] == color)
            return image;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    image[nr][nc] == initial_color) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};