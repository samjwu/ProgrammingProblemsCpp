class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set;
        int len = s.length();
        int ptr1 = 0;
        int ptr2 = 0;
        int ans = 0;
        
        while (ptr1 < len && ptr2 < len) {
            if (set.count(s[ptr2]) == 0) {
                set.insert(s[ptr2]);
                ptr2++;
                ans = max(ans, ptr2 - ptr1);
            } else {
                set.erase(s[ptr1]);
                ptr1++;
            }
        }
        
        return ans;
    }
};