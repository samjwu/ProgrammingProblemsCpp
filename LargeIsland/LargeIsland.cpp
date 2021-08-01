class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size();

        int groupNum = 2; // start at 2 to avoid confusion with grid numbers (0/1)
        unordered_map<int, int> groupSize;
        
        // determine groups
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    groupSize[groupNum] = dfs(grid, i, j, groupNum);
                    ans = max(ans, groupSize[groupNum]);
                    groupNum++;
                }
            }
        }
        
        // get biggest connected islands from 0s
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen = {};
                    int sz = 1;
                    
                    for (int k=0; k<4; k++) {
                        int nextI = i + dirs[k][0];
                        int nextJ = j + dirs[k][1];
                        
                        if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < n && grid[nextI][nextJ] > 1 && seen.count(grid[nextI][nextJ]) == 0) {
                            seen.insert(grid[nextI][nextJ]);
                            sz += groupSize[grid[nextI][nextJ]];
                        }
                    }
                    
                    ans = max(ans, sz);
                }
            }
        }
        
        return ans;
    }
    
private:
    int n;
    
    vector<vector<int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    
    int dfs(vector<vector<int>>& grid, int i, int j, int groupNum) {
        int sz = 1;
        grid[i][j] = groupNum;
        
        for (int k=0; k<4; k++) {
            int nextI = i + dirs[k][0];
            int nextJ = j + dirs[k][1];

            if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < n && grid[nextI][nextJ] == 1) {
                grid[nextI][nextJ] = groupNum;
                sz += dfs(grid, nextI, nextJ, groupNum);
            }
        }
        
        return sz;
    }
};