class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        int num = 1;
        for (int layer = 0; layer < (n+1) / 2; layer++) {
            for (int elem = layer; elem < n - layer; elem++) {
                ans[layer][elem] = num++;
            }
            
            for (int elem = layer + 1; elem < n - layer; elem++) {
                ans[elem][n - layer - 1] = num++;
            }
            
            for (int elem = n - layer - 2; elem >= layer; elem--) {
                ans[n - layer - 1][elem] = num++;
            }
            
            for (int elem = n - layer - 2; elem > layer; elem--) {
                ans[elem][layer] = num++;
            }
        }
        
        return ans;
    }
};