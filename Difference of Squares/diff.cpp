class Solution {
public:  
    bool dfs(int n, unordered_map<int, bool> &memo) {
        if (memo.count(n) == 1) {
            return memo[n];
        }
        int root = (int) sqrt((double) n);
        for (int i=1; i<=root; i++) {
            if (dfs(n - i*i, memo) == false) {
                memo[n] = true;
                return true;
            }
        }
        memo[n] = false;
        return false;
    }
    
    bool winnerSquareGame(int n) {
        unordered_map<int, bool> memo;
        memo[0] = false;
        memo[1] = true;
        
        return dfs(n, memo);
    }
};