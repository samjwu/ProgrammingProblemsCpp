class Solution {
public:
    int calcArea(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || i>=m || j<0 || j>=n || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
   
        visited[i][j] = true;
        
        return 1 + calcArea(grid, i-1, j) + calcArea(grid, i+1, j) + calcArea(grid, i, j-1) + calcArea(grid, i, j+1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int ans = 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                ans = max(ans, calcArea(grid, i, j));
            }
        }
        
        return ans;
    }
    
private:
    vector<vector<bool>> visited;
    int m, n;
};