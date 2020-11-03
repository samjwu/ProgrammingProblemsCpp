class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> unique;
        set<string> seen;
        vector<string> ans;
        if (s.length() <= 10) {
            return ans;
        }
        for (int i=0; i<=s.length()-10; i++) {
            if (unique.count(s.substr(i, 10)) > 0) {
                seen.insert(s.substr(i, 10));
            } else {
                unique.insert(s.substr(i, 10));
            }
        }
        for (string str:seen) {
            ans.push_back(str);
        }
        return ans;
    }
};