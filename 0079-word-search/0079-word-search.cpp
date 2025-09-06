class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (index == word.size()) return true; 
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if (board[i][j] != word[index]) return false;
        
        char temp = board[i][j];    
        board[i][j] = '#';          

        
        bool found = dfs(board, word, index + 1, i + 1, j) ||
                     dfs(board, word, index + 1, i - 1, j) ||
                     dfs(board, word, index + 1, i, j + 1) ||
                     dfs(board, word, index + 1, i, j - 1);

        board[i][j] = temp;         
        return found;
    }
};
