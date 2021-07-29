class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        
        bool hasSign = false;
        int beforeSign = 0;
        int afterSign = 0;
        
        bool hasDec = false;
        int beforeDec = 0;
        int afterDec = 0;
        
        bool hasE = false;
        int beforeE = 0;
        int afterE = 0;
        
        for (int i=0; i<n; i++) {
            if (isdigit(s[i])) {
                if (!hasDec) {
                    beforeDec++;
                } else {
                    afterDec++;
                }
                
                if (!hasE) {
                    beforeE++;
                } else {
                    afterE++;
                }
                
            } else { // letter, +, -, .
                if (s[i] == '+') {
                    if ((i > 0 && tolower(s[i-1]) != 'e') || (!hasE && i > 0)) {
                        return false;
                    }
                    hasSign = true;
                    
                } else if (s[i] == '-') {
                    if ((i > 0 && tolower(s[i-1]) != 'e') || (!hasE && i > 0)) {
                        return false;
                    }
                    hasSign = true;
                    
                } else if (s[i] == '.') {
                    if (hasDec || hasE) {
                        return false;
                    }
                    hasDec = true;
                    
                } else if (tolower(s[i]) == 'e') {
                    if (hasE) {
                        return false;
                    }
                    hasE = true;
                    
                } else { // letter
                    return false;
                }
            }
        }
        
        if ((beforeDec == 0 && afterDec == 0) || (hasE && (beforeE == 0 || afterE == 0))) {
            return false;
        }
        return true;
    }
};