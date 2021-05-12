class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memo = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                memo[i][j] = memo[i-1][j] + memo[i][j-1] + matrix[i-1][j-1] - memo[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return memo[row2+1][col2+1] - memo[row2+1][col1] - memo[row1][col2+1] + memo[row1][col1];
    }
    
private:
    int m, n;
    vector<vector<int>> memo;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */