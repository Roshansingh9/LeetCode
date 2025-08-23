class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> dummy;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {

                temp.push_back(matrix[j][i]);
            }
            reverse(temp.begin(),temp.end());
            dummy.push_back(temp);
        }
        matrix = dummy;
    }
};