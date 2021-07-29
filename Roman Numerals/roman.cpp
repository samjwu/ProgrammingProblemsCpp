class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        
        char prev;
        for (int i=s.length()-1; i>=0; i--) {
            char c = s[i];
            
            if (c == 'I') {
                if (prev == 'V' || prev == 'X') {
                    ans -= 1;
                } else {
                    ans += 1;
                }
            } else if (c == 'V') {
                ans += 5;
            } else if (c == 'X') {
                if (prev == 'L' || prev == 'C') {
                    ans -= 10;
                } else {
                    ans += 10;
                }
            } else if (c == 'L') {
                ans += 50;
            } else if (c == 'C') {
                if (prev == 'D' || prev == 'M') {
                    ans -= 100;
                } else {
                    ans += 100;
                }
            } else if (c == 'D') {
                ans += 500;
            } else if (c == 'M') {
                ans += 1000;
            }
            
            prev = c;
        }
        
        return ans;
    }
};