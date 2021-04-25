class Solution {
public:
    int m, n;
    
    void diag(vector<vector<int>>& matrix) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void vert(vector<vector<int>>& matrix) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<n/2; j++) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        diag(matrix);
        vert(matrix);
    }
};