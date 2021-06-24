class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        memo = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return recursiveMove(startRow, startColumn, maxMove);
    }
    
private:
    int mod = 1000000007;
    int m, n;
    vector<vector<vector<int>>> memo;
    
    int recursiveMove(int i, int j, int k) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 1;
        }
        
        if (k == 0) {
            return 0;
        }
        
        if (memo[i][j][k] != -1) {
            return memo[i][j][k];
        }
        
        int moves = ((recursiveMove(i-1, j, k-1) + recursiveMove(i+1, j, k-1)) % mod + (recursiveMove(i, j-1, k-1) +recursiveMove(i, j+1, k-1)) % mod) % mod;
        memo[i][j][k] = moves;
        return moves;
    }
};