class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;

    vector<string> board;
    vector<vector<int>> dpScore;
    vector<vector<int>> dpWays;
    vector<vector<bool>> vis;

    pair<int,int> dfs(int i, int j) {
        if (i >= n || j >= n || board[i][j] == 'X')
            return {-1000000000, 0};

        if (i == n - 1 && j == n - 1)
            return {0, 1};

        if (vis[i][j])
            return {dpScore[i][j], dpWays[i][j]};

        vis[i][j] = true;

        int best = -1000000000;
        long long ways = 0;

        vector<pair<int,int>> dir = {
            {i + 1, j},
            {i, j + 1},
            {i + 1, j + 1}
        };

        for (auto [x, y] : dir) {
            auto [score, cnt] = dfs(x, y);

            if (cnt == 0) continue;

            if (score > best) {
                best = score;
                ways = cnt;
            } else if (score == best) {
                ways = (ways + cnt) % MOD;
            }
        }

        if (ways == 0) {
            dpScore[i][j] = -1000000000;
            dpWays[i][j] = 0;
            return {dpScore[i][j], dpWays[i][j]};
        }

        int val = 0;
        if (board[i][j] >= '0' && board[i][j] <= '9')
            val = board[i][j] - '0';

        dpScore[i][j] = best + val;
        dpWays[i][j] = ways % MOD;

        return {dpScore[i][j], dpWays[i][j]};
    }

    vector<int> pathsWithMaxScore(vector<string>& b) {
        board = b;
        n = board.size();

        dpScore.assign(n, vector<int>(n, 0));
        dpWays.assign(n, vector<int>(n, 0));
        vis.assign(n, vector<bool>(n, false));

        auto [score, ways] = dfs(0, 0);

        if (ways == 0) return {0, 0};
        return {score, ways};
    }
};