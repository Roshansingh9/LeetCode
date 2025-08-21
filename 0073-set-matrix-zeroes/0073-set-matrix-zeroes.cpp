class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>> temp;
        int n=matrix.size();
        int m=matrix[0].size();
        for (int i = 0; i <n; i++) {
            for (int j = 0 ;j < m; j++) {
                if (matrix[i][j] == 0)
                    temp.push({i, j});
            }
        }
         while (!temp.empty()) {
            int x = temp.front().first;
            int y = temp.front().second;
            temp.pop();

            
            for (int j = 0; j < m; j++) {
                matrix[x][j] = 0;
            }

            
            for (int i = 0; i < n; i++) {
                matrix[i][y] = 0;
            }
        }
    }
};