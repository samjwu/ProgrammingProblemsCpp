class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int maxans = 1;
        for (int i=0; i<s.length(); i++) {
            maxans = max(ans, maxans);
            ans = 1;
            for (int j=i+1; j<s.length(); j++) {
                if (s[i] == s[j]) {
                    ans++;
                } else {
                    break;
                }
            }
        }
        return maxans;
    }
};