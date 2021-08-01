class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, amount+1);
        memo[0] = 0;
        
        for (int i=1; i<=amount; i++) {
            for (int coin: coins) {
                if (coin <= i) {
                    memo[i] = min(memo[i], memo[i-coin]+1);
                }
            }
        }
        
        if (memo[amount] > amount) {
            return -1;
        }
        return memo[amount];
    }
};