class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        stack<char> stk;
        
        for (char c: s) {
            if (!stk.empty() && stk.top() == c) {
                stk.pop();
                ans.pop_back();
                continue;
            }
            stk.push(c);
            ans.push_back(c);
        }
        
        return ans;
    }
};