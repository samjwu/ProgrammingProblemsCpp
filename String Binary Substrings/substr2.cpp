class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int pre = 0;
        int cur = 1;
        
        for (int i=0; i<s.length()-1; i++) {
            if (s[i] != s[i+1]) {
                ans += min(pre, cur);
                pre = cur;
                cur = 1;
            } else {
                cur++;
            }
        }
        
        return ans + min(pre, cur);
    }
};