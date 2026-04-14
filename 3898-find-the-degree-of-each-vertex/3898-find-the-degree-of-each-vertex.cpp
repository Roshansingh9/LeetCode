class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            result[i]=accumulate(matrix[i].begin(),matrix[i].end(),0);
        }
        return result;
    }
};