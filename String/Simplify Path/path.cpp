class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        stringstream ss(path);
        string str;
        string ans;
        
        while (getline(ss, str, '/')) {
            if (str == "" || str == ".") {
                continue;
            }
            
            if (str == ".." && !stk.empty()) {
                stk.pop();
            } else if (str != "..") {
                stk.push(str);
            }
        }
        
        while (!stk.empty()) {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        
        if (ans.empty()) {
            return "/";   
        }
        return ans;
    }
};