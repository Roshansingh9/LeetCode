class Solution {
public:
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));
        
     
        for(int i = 0; i < m; i++) dfs(heights, pac, i, 0, heights[i][0]);
        for(int j = 0; j < n; j++) dfs(heights, pac, 0, j, heights[0][j]);
        
      
        for(int i = 0; i < m; i++) dfs(heights, atl, i, n-1, heights[i][n-1]);
        for(int j = 0; j < n; j++) dfs(heights, atl, m-1, j, heights[m-1][j]);
        
        vector<vector<int>> result;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pac[i][j] && atl[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int i, int j, int prevHeight) {
       
        if(i < 0 || j < 0 || i >= m || j >= n || ocean[i][j] || heights[i][j] < prevHeight) return;
        
        ocean[i][j] = 1;
        
       
        dfs(heights, ocean, i+1, j, heights[i][j]);
        dfs(heights, ocean, i-1, j, heights[i][j]);
        dfs(heights, ocean, i, j+1, heights[i][j]);
        dfs(heights, ocean, i, j-1, heights[i][j]);
    }
};
