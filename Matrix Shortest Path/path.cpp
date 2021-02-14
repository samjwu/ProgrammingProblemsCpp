class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;
        
        if (grid[0][0] == 1 || grid[n][m] == 1) {
            return -1;
        }
        
        vector<vector<int>> dirs = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0}, {1, 1}};
        queue<vector<int>> q;
        q.push({0, 0, 1});
        
        while (!q.empty()) {
            vector<int> cell = q.front();
            q.pop();
            
            if (cell[0] == n && cell[1] == m) {
                return cell[2];
            }
            
            for (vector<int> dir: dirs) {
                int x = cell[0] + dir[0];
                int y = cell[1] + dir[1];
                
                if (x >= 0 && x <= n && y >= 0 && y <= m && grid[x][y] == 0) {
                    grid[x][y] = 1;
                    q.push({x, y, cell[2] + 1});
                }
            }
        }
        
        return -1;
    }
};