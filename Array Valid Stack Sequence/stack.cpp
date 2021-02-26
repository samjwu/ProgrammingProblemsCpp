class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        
        int n = pushed.size();
        int i = 0;
        
        for (int num: pushed) {
            stk.push(num);
            
            while (!stk.empty() && i<n && stk.top() == popped[i]) {
                stk.pop();
                i++;
            }
        }
        
        return i==n;
    }
};