class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> map;
        int len = s.length();
        int ans = 0;
        
        for (int i = 0, j = 0; j < len; j++) {
            if (map.find(s[j]) != map.end()) {
                i = max(i, map[s[j]]);
            }
            
            ans = max(ans, j - i + 1);
            map[s[j]] = j + 1;
        }
        
        return ans;
    }
};