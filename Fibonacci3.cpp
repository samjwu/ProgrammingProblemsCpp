class Solution {
public:
    unordered_map<int, int> memo;
    
    int dp(int n) {
       for (int i=2; i<=n; i++) {
           memo[i] = memo[i-2] + memo[i-1];
       }
        
        return memo[n];
    }
    
    int fib(int n) {
        memo[0] = 0;
        memo[1] = 1;
        return dp(n);
    }
};