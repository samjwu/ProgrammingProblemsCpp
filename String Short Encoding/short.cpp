class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> set(words.begin(), words.end());
        for (string word: words) {
            for (int i=1; i<word.length(); i++) {
                set.erase(word.substr(i));
            }
        }
        
        int ans = 0;
        for (string word: set) {
            ans += word.length() + 1;
        }
        
        return ans;
    }
};