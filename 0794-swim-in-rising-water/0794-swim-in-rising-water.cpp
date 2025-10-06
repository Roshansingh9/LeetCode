class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

       
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if(r == n-1 && c == n-1) return time;

            for(auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    pq.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};