class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if (m == 1) {
            return triangle[0][0]; 
        }
        
        vector<int> prev(m);
        vector<int> curr(m);
        prev[0] = triangle[0][0];
        
        for (int i=1; i<m; i++) {
            int n = triangle[i].size();
            for (int j=0; j<n; j++) {
                if (j > 0 && j < n-1) {
                    curr[j] = triangle[i][j] + min(prev[j-1], prev[j]); 
                } else if (j == 0) {
                    curr[j] = triangle[i][j] + prev[j];
                } else { // j == n-1
                    curr[j] = triangle[i][j] + prev[j-1];
                }
            }
            prev = curr;
        }
        
        return *min_element(curr.begin(), curr.end());
    }
};