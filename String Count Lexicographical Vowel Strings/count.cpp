class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> memo(n+1, vector<int>(6));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                if (i > 1) {
                    memo[i][j] = memo[i][j-1] + memo[i-1][j];
                } else {
                    memo[i][j] = memo[i][j-1] + 1;
                }
            }
        }
        
        return memo[n][5];
    }
};