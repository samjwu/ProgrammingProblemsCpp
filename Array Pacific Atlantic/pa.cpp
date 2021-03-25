class Solution {
public:
    vector<vector<bool>> dfs(vector<vector<int>>& matrix, queue<vector<int>>& q) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> ans(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        
        while (!q.empty()) {
            vector<int> cell = q.front();
            q.pop();
            
            ans[cell[0]][cell[1]] = true;
            for (vector<int> dir: dirs) {
                int i = cell[0] + dir[0];
                int j = cell[1] + dir[1];
                
                if (i < 0 || i >= m || j < 0 || j >= n) {
                    continue;
                }
                
                if (ans[i][j]) {
                    continue;
                }
                
                if (matrix[i][j] < matrix[cell[0]][cell[1]]) {
                    continue;
                }
                
                q.push({i, j});
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        
        int m = matrix.size();
        if (m == 0) {
            return ans;
        }
        
        int n = matrix[0].size();
        if (n == 0) {
            return ans;
        }
        
        queue<vector<int>> pq, aq;
        for (int i=0; i<m; i++) {
            pq.push({i, 0});
            aq.push({i, n-1});
        }
        for (int j=0; j<n; j++) {
            pq.push({0, j});
            aq.push({m-1, j});
        }
        
        vector<vector<bool>> canPacific = dfs(matrix, pq);
        vector<vector<bool>> canAtlantic = dfs(matrix, aq);
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (canPacific[i][j] && canAtlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};