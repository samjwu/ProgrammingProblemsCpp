class Solution {
public:
    int decodeCount(string& s, int i, vector<int>& memo) {
        if (memo[i] > -1) {
            return memo[i];
        }
        
        if (s[i] == '0') {
            memo[i] = 0;
            return memo[i];
        }
        
        int ans = decodeCount(s, i+1, memo);
        
        if (i < s.length() - 1 && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) {
            ans += decodeCount(s, i+2, memo);
        }
        
        memo[i] = ans;
        return memo[i];
    }
    
    int numDecodings(string s) {
        if (s.length() == 0) {
            return 0;
        }
        
        int n = s.length();
        vector<int> memo(n+1, -1);
        memo[n] = 1;
        return decodeCount(s, 0, memo);
    }
};