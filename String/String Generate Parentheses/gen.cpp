class Solution {
public:
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return ans;
    }
    
private:
    vector<string> ans;

    void backtrack(string s, int open, int close, int n) {
        if (s.length() == n*2 && open == n && close == n) {
            ans.push_back(s);
        }
        
        if (open < n) {
            s.push_back('(');
            backtrack(s, open+1, close, n);
            s.pop_back();
        }
        
        if (close < open) {
            s.push_back(')');
            backtrack(s, open, close+1, n);
            s.pop_back();
        } 
        
    }
};