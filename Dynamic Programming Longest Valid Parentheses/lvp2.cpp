class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.length();
        vector<int> memo(n);
        
        for (int i=0; i<n-1; i++) {
            if (s[i] == '(' && s[i+1] == ')') {
                memo[i+1] = 2;
                if (i >= 1) {
                    memo[i+1] += memo[i-1];
                }
            } else if (s[i] == ')' && s[i+1] == ')') {
                if (i - memo[i] >= 0 && s[i - memo[i]] == '(') {
                    memo[i+1] = memo[i] + 2;
                    if (i - memo[i] >= 1) {
                        memo[i+1] += memo[i - memo[i] - 1];
                    }
                }
            }
            
            ans = max(ans, memo[i+1]);
        }
        
        return ans;
    }
};