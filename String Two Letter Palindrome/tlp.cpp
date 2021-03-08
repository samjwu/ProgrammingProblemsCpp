class Solution {
public:
    bool isPalindrome(string s) {
        int end = s.length();
        for (int i=0; i<end/2; i++) {
            if (s[i] != s[end-1-i]) {
                return false;
            }
        }
        
        return true;
    }
    
    int removePalindromeSub(string s) {
        if (s.length() == 0) {
            return 0;
        }
        
        if (isPalindrome(s)) {
            return 1;
        }
        
        return 2;
    }
};