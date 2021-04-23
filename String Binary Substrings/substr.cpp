class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        
        int first = 0;
        int second = 0;
        int count = 1;
        
        bool curr;
        if (s[0] == '0') {
            curr = 0;
        } else {
            curr = 1;
        }
        
        for (int i=1; i<s.length(); i++) {
            if (s[i] == '0') {
                if (curr == 1) {
                    curr = 0;
                    first = second;
                    second = count;
                    ans += min(first, second);
                    count = 0;
                }
                count++;
            } else {
                if (curr == 0) {
                    curr = 1;
                    first = second;
                    second = count;
                    ans += min(first, second);
                    count = 0;
                }
                count++;
            }
        }
        
        ans += min(second, count);
        
        return ans;
    }
};