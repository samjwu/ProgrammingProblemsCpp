class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        for (int i=1; i<m; i++) {
            int n = triangle[i].size();
            for (int j=0; j<n; j++) {
                if (j > 0 && j < n-1) {
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                } else if (j == 0) {
                    triangle[i][j] += triangle[i-1][j];
                } else { // j == n-1
                    triangle[i][j] += triangle[i-1][j-1];
                }
            }
        }
        
        return *min_element(triangle[m-1].begin(), triangle[m-1].end());
    }
};