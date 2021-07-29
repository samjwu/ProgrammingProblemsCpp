class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> memo(n+1, vector<int>(m+1, 0));
        int ones, zeroes;
        
        for (auto s: strs) {
            ones = count(s.begin(), s.end(), '1');
            zeroes = count(s.begin(), s.end(), '0');
            for (int i=n; i>=ones; i--) {
                for (int j=m; j>=zeroes; j--) {
                    memo[i][j] = max(memo[i][j], memo[i-ones][j-zeroes] + 1);
                }
            }
        }
        
        return memo[n][m];
    }
};