class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stk;
        stk.push(-1);
        
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            
            if (c == '(') {
                stk.push(i);
            } else {
                if (!stk.empty()) {
                    stk.pop();
                }
                
                if (!stk.empty()) {
                    ans = max(ans, i - stk.top());
                } else {
                    stk.push(i);
                }
            }
        }
        
        return ans;
    }
};