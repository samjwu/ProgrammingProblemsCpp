class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        
        unordered_map<char, int> word1Chars, word2Chars;
        unordered_map<int, int> word1CharFreq, word2CharFreq;
        set<char> word1Set, word2Set;
        
        for (char c : word1) {
            word1Chars[c]++;
            word1Set.insert(c);
        }
        for (char c : word2) {
            word2Chars[c]++;
            word2Set.insert(c);
        }
        
        if (word1Set != word2Set) {
            return false;
        }
        
        for (auto pair : word1Chars) {
            word1CharFreq[pair.second]++;    
        }
        for (auto pair : word2Chars) {
            word2CharFreq[pair.second]++;    
        }
        
        for (auto pair : word1CharFreq) {
            if (pair.second != word2CharFreq[pair.first]) {
                return false;
            }
        }
        
        return true;
    }
};