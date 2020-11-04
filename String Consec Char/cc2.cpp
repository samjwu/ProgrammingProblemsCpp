class Solution {
public:
    int maxPower(string s) {
        if (s.length() == 1) {
            return 1;
        }
        int ans = 1;
        int maxans = 0;
        for (int i=0; i<s.length()-1; i++) {
            if (s[i] == s[i+1]) {
                ans++;
            } else {
                ans = 1;
            }
            maxans = max(ans, maxans);
        }
        return maxans;
    }
};