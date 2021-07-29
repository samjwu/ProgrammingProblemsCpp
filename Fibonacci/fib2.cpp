class Solution {
public:
    unordered_map<int, int> memo;
    
    int dp(int n) {
        if (n <= 0) {
            return 0;
        }
        
        if (memo[n] > 0) {
            return memo[n];
        }
        
        memo[n] = dp(n-2) + dp(n-1);
        
        return memo[n];
    }
    
    int fib(int n) {
        memo[0] = 0;
        memo[1] = 1;
        return dp(n);
    }
};