class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> map;
        
        int m = mat.size();
        int n = mat[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i-j].push_back(mat[i][j]);
            }
        }
        
        for (int k = 1-n; k < m; k++) {
            sort(map[k].begin(), map[k].end());
        }
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                mat[i][j] = map[i-j].back();
                map[i-j].pop_back();
            }
        }
        
        return mat;
    }
};