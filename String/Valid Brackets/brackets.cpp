class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) {
                    return false;
                }
                char brkt = stk.top();
                stk.pop();
                if ((brkt == '(' && s[i] != ')') ||
                   (brkt == '[' && s[i] != ']') ||
                   (brkt == '{' && s[i] != '}')) {
                    return false;
                }
            }
        }
        
        return stk.empty();
    }
};