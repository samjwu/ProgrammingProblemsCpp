class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if (m*n != r*c) {
            return mat;
        }
        
        vector<int> vec;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                vec.push_back(mat[i][j]);
            }
        }
        
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                ans[i][j] = vec[i*c + j];
            }
        }
        
        return ans;
    }
};