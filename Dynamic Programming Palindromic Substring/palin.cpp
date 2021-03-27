class Solution {
public:
    int countSubstrings(string s) {
        unordered_map<int, unordered_map<int, bool>> memo;
        
        int n = s.length();
        int ans = 0;
        
        if (n == 0) {
            return ans;
        }
        
        for (int i=0; i<n; i++) {
            memo[i][i] = true;
            ans++;
        }
        
        for (int i=0; i<n-1; i++) {
            if (s[i] == s[i+1]) {
                memo[i][i+1] = true;
                ans++;
            }
        }
        
        for (int len=3; len<=n; len++) {
            for (int i=0, j=i+len-1; j<n; i++, j++) {
                if (s[i] == s[j] && memo[i+1][j-1] == true) {
                    memo[i][j] = true;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};