class Solution {
public:  
    bool dfs(int n, vector<int> &memo) {
        if (memo[n] != -1) {
            return memo[n];
        }
        int root = (int) sqrt((double) n);
        for (int i=1; i<=root; i++) {
            if (dfs(n - i*i, memo) == 0) {
                memo[n] = 1;
                return true;
            }
        }
        memo[n] = 0;
        return false;
    }
    
    bool winnerSquareGame(int n) {
        vector<int> memo(n+1, -1);
        memo[0] = 0;
        memo[1] = 1;
        
        return dfs(n, memo);
    }
};