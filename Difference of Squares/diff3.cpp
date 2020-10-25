class Solution {
public: 
    bool winnerSquareGame(int n) {
        unordered_map<int, bool> memo;
        memo[0] = false;
        memo[1] = true;
        
        for (int i=0; i<=n; i++) {
            for (int j=1; j*j<=i; j++) {
                if (memo[i-j*j] == false) {
                    memo[i] = true;
                    break;
                }
            }
        }
        
        return memo[n];
    }
};