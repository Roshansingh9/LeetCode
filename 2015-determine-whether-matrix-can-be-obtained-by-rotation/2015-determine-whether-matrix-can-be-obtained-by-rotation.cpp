class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int k = 0; k < 4; ++k) {
            if (isEqual(mat, target))
                return true;
            rotate90(mat);
        }
        return false;
    }

private:
    void rotate90(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n ; ++i) {
            for (int j = i+1; j < n ; ++j) {
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }

    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != target[i][j])
                    return false;
            }
        }
        return true;
    }
};