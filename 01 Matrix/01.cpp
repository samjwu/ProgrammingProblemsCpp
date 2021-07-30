class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<vector<int>> q;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            vector<int> coord = q.front();
            q.pop();
            
            for (int i=0; i<4; i++) {
                int nextX = coord[0] + moves[i][0];
                int nextY = coord[1] + moves[i][1];
                    
                if (nextX >= 0 && nextX <= m-1 && nextY >= 0 && nextY <= n-1) {
                    if (ans[nextX][nextY] > ans[coord[0]][coord[1]] + 1) {
                        ans[nextX][nextY] = ans[coord[0]][coord[1]] + 1;
                        q.push({nextX, nextY});
                    }
                }
            }
        }
        
        return ans;
    }
    
private:
    int m, n;
    vector<vector<int>> moves = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
};