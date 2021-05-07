class Solution {
public:
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return recurse(word1, word2, 0, 0);
    }

private:
    int m, n;
    vector<vector<int>> memo;
    
    int recurse(string& w1, string& w2, int i, int j) {
        if (i == m && j == n) {
            return 0;
        }
        if (i == m) {
            return n-j;
        }
        if (j == n) {
            return m-i;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        if (w1[i] == w2[j]) {
            return recurse(w1, w2, i+1, j+1);
        }
        
        memo[i][j] = 1 + min(recurse(w1, w2, i+1, j), recurse(w1, w2, i, j+1));
        return memo[i][j];
    }
};