class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for (string& token: tokens) {
            if (token.compare("+") == 0) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a+b);
            } else if (token.compare("-") == 0) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a-b);
            } else if (token.compare("*") == 0) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a*b);
            } else if (token.compare("/") == 0) {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a/b);
            } else {
                stk.push(stoi(token));
            }
        }
        
        return stk.top();
    }
};