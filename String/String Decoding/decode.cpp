class Solution {
public:
    string decodeString(string s) {
        stack<string> subans;
        stack<int> count;
        string ans;
        int k = 0;
        
        for (int i=0; i<s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans.push_back(s[i]);
            } else if (s[i] == '[') {
                subans.push(ans);
                ans.clear();
                count.push(k);
                k = 0;
            } else if (s[i] == ']') {
                string suffix = ans;
                ans = subans.top();
                subans.pop();
                int n = count.top();
                count.pop();
                k = 0;
                while (n > 0) {
                    ans.append(suffix);
                    n--;
                }
            } else {
                k = (k * 10) + (s[i] - '0');
            }
        }
            
        return ans;
    }
};