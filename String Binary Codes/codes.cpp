class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> set;
        
        for (int i=0; i<= (int)s.length()-k; i++) {
            set.insert(s.substr(i, k));
        }
        
        return set.size() == pow(2, k);
    }
};