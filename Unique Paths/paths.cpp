class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        
        for (int i=0; i<m; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            memo[i][0] = 1;
        }
        for (int j=0; j<n; j++) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            memo[0][j] = 1;
        }
        
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }
        
        return memo[m-1][n-1];
    }
};