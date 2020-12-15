class Solution {
public:
    bool palindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }    
        }
        
        return true;
    }
    
    void backtrack(vector<vector<string>>& ans, string& s, int start, vector<string>& substrings) {
        if (start >= s.length()) {
            ans.push_back(substrings);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (palindrome(s, start, end)) {
                substrings.push_back(s.substr(start, end - start + 1));
                backtrack(ans, s, end + 1, substrings);
                substrings.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> substrings;
        backtrack(ans, s, 0, substrings);
        return ans;
    }
};