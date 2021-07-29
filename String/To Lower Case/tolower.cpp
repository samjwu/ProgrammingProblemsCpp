class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        
        for (char c: s) {
            if (c >= 'A' && c <= 'Z') {
                ans.push_back(c-'A'+'a');
            } else {
                ans.push_back(c);
            }
        }
        
        return ans;
    }
};