class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1000000007;
        vector<vector<int>> memo = vector<vector<int>>(n+1, vector<int>(k+1, 0));
        
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=k; j++) {
                if (j == 0) {
                    memo[i][j] = 1;
                } else {
                    int val = memo[i-1][j] + mod;
                    
                    if (j >= i) {
                        val -= memo[i-1][j-i];
                    }
                    
                    val %= mod;
                    memo[i][j] = (memo[i][j-1] + val) % mod;
                }
            }
        }
        
        if (k > 0) {
            return (memo[n][k] + mod - memo[n][k-1]) % mod;
        }
        return (memo[n][k] + mod) % mod;
    }
};