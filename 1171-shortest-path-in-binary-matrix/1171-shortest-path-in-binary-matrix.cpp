class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<pair<int,int>, int>> q;

        q.push({{0,0},1});
        dist[0][0] = 1;

        int dx[] = {-1,-1,-1,0,+1,+1,+1,0};
        int dy[] = {-1,0,+1,+1,+1,0,-1,-1};

        while(!q.empty()){
            auto [cell, dis] = q.front(); q.pop();
            int r = cell.first, c = cell.second;

            for(int i=0; i<8; i++){
                int nr = r + dx[i], nc = c + dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && dist[nr][nc] > dis+1){
                    if(nr == n-1 && nc == n-1) return dis+1;
                    dist[nr][nc] = dis+1;
                    q.push({{nr,nc}, dis+1});
                }
            }
        }
        return (dist[n-1][n-1] == INT_MAX) ? -1 : dist[n-1][n-1];
    }
};
