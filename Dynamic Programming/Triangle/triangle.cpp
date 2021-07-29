class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        vector<vector<int>> memo(m, vector<int>(m));
        memo[0][0] = triangle[0][0];
        
        for (int i=1; i<m; i++) {
            int n = triangle[i].size();
            for (int j=0; j<n; j++) {
                if (j > 0 && j < n-1) {
                    memo[i][j] = triangle[i][j] + min(memo[i-1][j-1], memo[i-1][j]);
                } else if (j == 0) {
                    memo[i][j] = triangle[i][j] + memo[i-1][j];
                } else { // j == n-1
                    memo[i][j] = triangle[i][j] + memo[i-1][j-1];
                }
            }
        }
        
        return *min_element(memo[m-1].begin(), memo[m-1].end());
    }
};