class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        
        vector<int> dp = triangle[n - 1];

        
        for (int i = n - 2; i >= 0; --i) {
            vector<int> current(triangle[i].size());
            for (int j = 0; j < triangle[i].size(); ++j) {
                int down = dp[j];
                int diagonal = dp[j + 1];
                current[j] = triangle[i][j] + min(down, diagonal);
            }
            dp = current; 
        }

        return dp[0]; 
    }
};
