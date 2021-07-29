class Solution {
public:
    int numDecodings(string s) {
        n = s.length();
        memo = vector<long long>(n, -1);
        return (int) numDecodingsAt(s, n-1);
    }
    
private:
    const int mod = 1000000007;
    int n;
    vector<long long> memo;
    
    long long numDecodingsAt(string& s, int idx) {
        if (idx < 0) {
            return 1;
        }
        
        if (memo[idx] != -1) {
            return memo[idx];
        }
        
        if (s[idx] == '*') {
            long long ans = 9 * numDecodingsAt(s, idx-1) % mod;
            
            if (idx > 0 && s[idx-1] == '1') {
                ans = (ans + 9 * numDecodingsAt(s, idx-2)) % mod;
            } else if (idx > 0 && s[idx-1] == '2') {
                ans = (ans + 6 * numDecodingsAt(s, idx-2)) % mod;
            } else if (idx > 0 && s[idx-1] == '*') {
                ans = (ans + 15 * numDecodingsAt(s, idx-2)) % mod;
            }
            
            memo[idx] = ans;
            return memo[idx];
        }
        
        long long ans;
        if (s[idx] == '0') {
            ans = 0;
        } else {
            ans = numDecodingsAt(s, idx-1);
        }
        
        if (idx > 0 && s[idx-1] == '1') {
            ans = (ans + numDecodingsAt(s, idx-2)) % mod;
        } else if (idx > 0 && s[idx-1] == '2' && s[idx] <= '6') {
            ans = (ans + numDecodingsAt(s, idx-2)) % mod;
        } else if (idx > 0 && s[idx-1] == '*') {
            ans = (ans + numDecodingsAt(s, idx-2)) % mod;
            if (s[idx] <= '6') {
                ans = (ans + numDecodingsAt(s, idx-2)) % mod;
            }
        }
        
        memo[idx] = ans;
        return memo[idx];
    }
};