class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int totalCodes = 1 << k; // pow(2, k)
        int subStrCount = s.length() - k + 1;
        
        if (subStrCount < totalCodes) {
            return false;
        }
        
        set<string> set;
        
        for (int i=0; i<subStrCount; i++) {
            set.insert(s.substr(i, k));
        }
        
        return set.size() == totalCodes;
    }
};