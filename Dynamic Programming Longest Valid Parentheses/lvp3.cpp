class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int l = 0;
        int r = 0;
        
        for (char c: s) {
            if (c == '(') {
                l++;
            } else {
                r++;
            }
            
            if (l == r) {
                ans = max(ans, l+r);
            } else if (r > l) {
                l = 0;
                r = 0;
            }
        }
        
        l = 0;
        r = 0;
        for (int i=s.length()-1; i>=0; i--) {
            if (s[i] == '(') {
                l++;
            } else {
                r++;
            }
            
            if (l == r) {
                ans = max(ans, l+r);
            } else if (l > r) {
                l = 0;
                r = 0;
            }
        }
        
        return ans;
    }
};