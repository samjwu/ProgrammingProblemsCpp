class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        n = pattern.length();
        
        for (string word: words) {
            if (patternMatch(word, pattern)) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
    
private:
    int n;
    
    bool patternMatch(string& word, string& pattern) {
        if (word.length() != n) {
            return false;
        }
        
        unordered_map<char, char> bijectiveMap;
        unordered_set<char> usedChars;
        
        for (int i=0; i<n; i++) {
            if (bijectiveMap.find(pattern[i]) != bijectiveMap.end() && bijectiveMap[pattern[i]] != word[i]) {
                return false;
            } else if (usedChars.count(word[i]) && bijectiveMap[pattern[i]] != word[i]) {
                return false;
            } else {
                usedChars.insert(word[i]);
                bijectiveMap[pattern[i]] = word[i];
            }
        }
        
        return true;
    }
};