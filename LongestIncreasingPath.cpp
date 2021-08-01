class Solution {
public:    
    int bfs(vector<vector<int>>& matrix) {
        int ans = 0;
        
        while (!q.empty()) {
            int qLen = q.size();
            ans++;
            
            for (int neighbor=0; neighbor<qLen; neighbor++) {
                vector<int> cell = q.front();
                q.pop();
            
                for (auto dir: dirs) {
                    int k = cell[0] + dir[0];
                    int l = cell[1] + dir[1];
                    if (k > -1 && l > -1 && k < m && l < n && matrix[k][l] > matrix[cell[0]][cell[1]] && --inDegree[k][l] == 0) {
                        q.push({k, l});
                    }
                }
            }
        }
        
        return ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        inDegree = vector<vector<int>>(m, vector<int>(n, 0));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int inDegreeCount = 0;
                
                for (auto dir: dirs) {
                    int k = i + dir[0];
                    int l = j + dir[1];
                    if (k > -1 && l > -1 && k < m && l < n && matrix[k][l] < matrix[i][j]) {
                        inDegreeCount++;
                    }
                }
                
                inDegree[i][j] = inDegreeCount;
                
                if (inDegree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        return bfs(matrix);
    }

private:
    int m, n;
    vector<vector<int>> inDegree;
    vector<vector<int>> dirs = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    queue<vector<int>> q;
};