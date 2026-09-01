class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        // Give every litter cell a bit index
        vector<vector<int>> id(n, vector<int>(m, -1));

        int sx = 0, sy = 0;
        int litter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litter++;
                }
            }
        }

        // No litter
        if (litter == 0)
            return 0;

        int totalMask = (1 << litter) - 1;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litter, false)
                )
            )
        );

        // row, col, current energy, collected mask
        queue<tuple<int, int, int, int>> q;

        q.push({sx, sy, energy, 0});
        visited[sx][sy][energy][0] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [x, y, curEnergy, mask] = q.front();
                q.pop();

                // Collected everything
                if (mask == totalMask)
                    return moves;

                // Can't move without energy
                if (curEnergy == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    // Outside grid
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    // Wall
                    if (classroom[nx][ny] == 'X')
                        continue;

                    int newEnergy = curEnergy - 1;
                    int newMask = mask;

                    // Recharge
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {
                        int bit = id[nx][ny];
                        newMask |= (1 << bit);
                    }

                    if (!visited[nx][ny][newEnergy][newMask]) {

                        visited[nx][ny][newEnergy][newMask] = true;

                        q.push({
                            nx,
                            ny,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};