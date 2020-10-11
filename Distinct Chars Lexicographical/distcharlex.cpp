class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);
        
        for (int i=0; i<s.length(); i++) {
            freq[s[i]-'a'] += 1;
        }
        
        for (int i=0; i<s.length(); i++) {
            freq[s[i]-'a'] -= 1;
            
            if (visited[s[i]-'a']==true) {
                continue;
            }
            
            while (ans.back()>s[i] && freq[ans.back()-'a']>0) {
                visited[ans.back()-'a'] = false;
                ans.pop_back();
            }

            visited[s[i]-'a'] = true;
            ans.push_back(s[i]);
        }
        
        return ans;
    }
};