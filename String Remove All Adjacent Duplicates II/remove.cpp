class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        string ans;
        
        for (int i=0; i<s.length(); i++) {
            if (stk.empty()) {
                stk.push({s[i], 1});
                ans.push_back(s[i]);
                
            } else {
                auto top = stk.top();
                
                if (top.first == s[i]) {
                    stk.pop();
                    
                    if (top.second == k-1) {
                        for (int j=0; j<k-1; j++) {
                            ans.pop_back();
                        }
                        
                    } else {
                        stk.push({s[i], top.second + 1});
                        ans.push_back(s[i]);
                    }
                    
                } else {
                    stk.push({s[i], 1});
                    ans.push_back(s[i]);
                }
            }
        }
        
        return ans;
    }
};