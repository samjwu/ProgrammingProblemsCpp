class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk;
        stk.push(0);
        
        for (char c: S) {
            if (c == '(') {
                stk.push(0);
            } else {
                int score1 = stk.top();
                stk.pop();
                int score2 = stk.top();
                stk.pop();
                stk.push(score2 + max(score1 * 2, 1));
            }
        }
        
        return stk.top();
    }
};