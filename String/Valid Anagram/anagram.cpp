class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> freqS, freqT;
        
        for (char c : s) {
            freqS[c]++;
        }
        
        for (char c : t) {
            freqT[c]++;
        }
        
        for (auto pair : freqS) {
            if (pair.second != freqT[pair.first]) {
                return false;
            }
        }
        
        return true;
    }
};