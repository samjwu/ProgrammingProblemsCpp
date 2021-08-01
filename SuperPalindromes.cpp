class Solution {
public:
    bool isPalindrome(string& s) {
        int n = s.length();
        for (int i=0; i<n/2; i++) {
            if (s[i] != s[n-1-i]) {
                return false;
            }        
        }
        
        return true;
    }
    
    int superpalindromesInRange(string left, string right) {
        long long l = stoll(left);
        long long r = stoll(right);
        int ans = 0;
        
        for (int i=1; i<100000; i++) {
            string s = to_string(i);
            int n = s.length();
            for (int j=n-2; j>=0; j--) {
                s.push_back(s[j]);
            }            
            
            long long super = stoll(s) * stoll(s);
            string superStr = to_string(super);
            if (super > r) {
                break;
            } else if (super >= l && super <= r && isPalindrome(superStr)) {
                ans++;
            }
        }
        
        for (int i=1; i<100000; i++) {
            string s = to_string(i);
            int n = s.length();
            for (int j=n-1; j>=0; j--) {
                s.push_back(s[j]);
            }            
            
            long long super = stoll(s) * stoll(s);
            string superStr = to_string(super);
            if (super > r) {
                break;
            } else if (super >= l && super <= r && isPalindrome(superStr)) {
                ans++;
            }
        }
        
        return ans;
    }
};