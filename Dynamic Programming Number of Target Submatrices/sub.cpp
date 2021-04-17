class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i=0; i<m; i++) {
            for (int j=1; j<n; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        unordered_map<int, int> map;
        int ans = 0;
        
        for (int j=0; j<n; j++) {
            for (int k=j; k<n; k++) {
                int sum = 0;
                map.clear();
                map[0] = 1;
                
                for (int i=0; i<m; i++) {
                    sum += matrix[i][k];
                    if (j > 0) {
                        sum -= matrix[i][j-1];
                    }
                    
                    ans += map[sum - target];
                    
                    map[sum]++;
                }
            }
        }
        
        return ans;
    }
};