class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> alienWords = words;
        unordered_map<char,int> alienDict;
        
        for (int i=0; i<26; i++) {
            alienDict[order[i]] = i;
        }
        
        sort(alienWords.begin(), alienWords.end(), [&alienDict](string a, string b) {
            int minlen = min(a.length(), b.length());
            
            for (int i=0; i<minlen; i++) {
                if (a[i] != b[i]) {
                    return alienDict[a[i]] < alienDict[b[i]];
                }
            }
            
            return a.length() < b.length();
        });
        
        for (int i=0; i<words.size(); i++) {
            if (words[i].compare(alienWords[i]) != 0) {
                return false;
            }
        }
        
        return true;
        
        return words == alienWords;
    }
};