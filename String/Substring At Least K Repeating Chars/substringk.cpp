class Solution {
public:
    int longestSubstring(string s, int k) {
        set<char> uniqueChars;
        for (char c:s) {
            uniqueChars.insert(c);
        }
        
        int totalUnique = uniqueChars.size();
        unordered_map<char, int> count;
        
        int ans = 0;
        for (int currUnique = 1; currUnique <= totalUnique; currUnique++) {
            count.clear();
            int start = 0;
            int end = 0;
            int countCurrUnique = 0;
            int countCurrValid = 0;
            
            while (end < s.length()) {
                if (countCurrUnique <= currUnique) {
                    if (count[s[end]] == 0) {
                        countCurrUnique++;
                    }
                    count[s[end]]++;
                    if (count[s[end]] == k) {
                        countCurrValid++;
                    }
                    end++;
                } else {
                    if (count[s[start]] == k) {
                        countCurrValid--;
                    }
                    count[s[start]]--;
                    if (count[s[start]] == 0) {
                        countCurrUnique--;
                    }
                    start++;
                }
                
                if (countCurrUnique == currUnique && countCurrUnique == countCurrValid) {
                    ans = max(end - start, ans);
                }
            }
        }
        
        return ans;
    }
};