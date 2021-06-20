class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int n = grid.size();
        int ans = max(grid[0][0], grid[n-1][n-1]);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        
        while (!pq.empty()) {
            vector<int> currSquare = pq.top();
            pq.pop();
            
            ans = max(ans, currSquare[0]);
            
            for (int i=0; i<4; i++) {
                int row = currSquare[1] + dir[i];
                int col = currSquare[2] + dir[i+1];
                
                if (row >= 0 && row < n && col >= 0 && col < n && visited[row][col] == 0) {
                    if (row == n-1 && col == n-1) {
                        return ans;
                    }
                    
                    pq.push({grid[row][col], row, col});
                    visited[row][col] = 1;
                }
            }
        }
        
        return -1;
    }
};