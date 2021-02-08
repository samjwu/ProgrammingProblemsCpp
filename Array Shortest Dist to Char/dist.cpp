class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int len = s.length();
        vector<int> ans(len, INT_MAX);
        
        int dist = -1;
        for (int i=0; i<len; i++) {
            if (s[i] == c) {
                dist = 0;
            }
            
            if (dist > -1) {
                ans[i] = dist;
                dist++;
            }
        }
        
        dist = -1;
        for (int i=len-1; i>=0; i--) {
            if (s[i] == c) {
                dist = 0;
            }
            
            if (dist > -1) {
                ans[i] = min(ans[i], dist);
                dist++;
            }
        }
        
        return ans;
    }
};