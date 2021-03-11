class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        map<int, int> memo;
        return dp(coins, amount, memo);
    }
    
    int dp(vector<int>& coins, int amount, map<int, int>& memo) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }
        
        auto iter = memo.find(amount);
        if (iter != memo.end()) {
            return iter->second;
        }
        
        int ans = amount + 1;
        
        for (int i=0; i<coins.size(); i++) {
            int count = dp(coins, amount - coins[i], memo);
            if (count >= 0) {
                ans = min(ans, count);
            }
        }
        
        if (ans > amount) {
            memo[amount] = -1;
        } else {
            memo[amount] = ans + 1;
        }
        
        return memo[amount];
    }
};