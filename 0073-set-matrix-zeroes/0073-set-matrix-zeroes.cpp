class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
       
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
           for (int j = 0; j < m; j++) {
                matrix[x][j] = 0;
            }

            
            for (int i = 0; i < n; i++) {
                matrix[i][y] = 0;
            }
        }
    }
};