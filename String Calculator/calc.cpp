class Solution {
public:
    int calculate(string s) {
        int start = 0;
        int prev = 0;
        int curr;
        int res = 0;
        char op = '+';
        
        auto end = remove(s.begin(), s.end(), ' ');
        s.erase(end, s.end());
        
        for (int i=0; i<s.length(); i++) {
            while (s[i] >= '0' && s[i] <= '9') {
                i++;
            }
            curr = stoi(s.substr(start, i-start));
            start = i+1;
            
            if (op == '+') {
                res += prev;
                prev = curr;
            } else if (op == '-') {
                res += prev;
                prev = -curr;
            } else if (op == '*') {
                prev = prev * curr;
            } else if (op == '/') {
                prev = prev / curr;
            }
            op = s[i];
        }
        res += prev;
        
        return res;
    }
};