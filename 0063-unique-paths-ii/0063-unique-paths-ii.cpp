class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int>prev(n,0);
        if (obstacleGrid[0][0] == 1) return 0;
        prev[0] = 1;

        for(int i = 0; i < m; i++) {
            vector<int> temp(n,0);
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    temp[j] = 0;

                } else {
                    int left=(j>0)?temp[j-1]:0;
                    int up=prev[j];
                    temp[j]=up+left;
                }
            }
            prev=temp;
        }

        return prev[n-1];
    }
};
