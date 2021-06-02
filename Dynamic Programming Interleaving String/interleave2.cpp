class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        if (m+n != s3.length()) {
            return false;
        }
        
        vector<vector<bool>> memo(m+1, vector<bool>(n+1, false));
        
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                if (i == 0 && j == 0) {
                    memo[i][j] = true;
                } else if (i == 0) {
                    if (memo[i][j-1] == true && s2[j-1] == s3[i+j-1]) {
                        memo[i][j] = true;
                    }
                } else if (j == 0) {
                    if (memo[i-1][j] == true && s1[i-1] == s3[i+j-1]) {
                        memo[i][j] = true;
                    }
                } else {
                    if (memo[i][j-1] == true && s2[j-1] == s3[i+j-1]) {
                        memo[i][j] = true;
                    } else if (memo[i-1][j] == true && s1[i-1] == s3[i+j-1]) {
                        memo[i][j] = true;
                    }
                }
            }
        }
        
        return memo[m][n];
    }
};