class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seen;
        vector<string> ans;
        if (s.length() <= 10) {
            return ans;
        }
        for (int i=0; i<=s.length()-10; i++) {
            seen[s.substr(i, 10)]++;
        }
        for (pair p:seen) {
            if (p.second > 1) {
                ans.push_back(p.first);    
            }
        }
        return ans;
    }
};