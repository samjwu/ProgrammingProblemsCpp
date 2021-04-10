class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (memo[i][j] > 0) {
            return memo[i][j];
        }
        
        int ans = 0;
        
        for (auto dir: dirs) {
            int k = i + dir[0];
            int l = j + dir[1];
            if (k > -1 && l > -1 && k < m && l < n && matrix[i][j] < matrix[k][l]) {
                ans = max(ans, dfs(matrix, k, l));            
            }
        }
        
        memo[i][j] = ans + 1;
        return memo[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, 0));
        int ans = 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        
        return ans;
    }
    
private:
    int m, n;
    vector<vector<int>> memo;
    vector<vector<int>> dirs = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
};