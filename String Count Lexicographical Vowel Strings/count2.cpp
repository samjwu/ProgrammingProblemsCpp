class Solution {
public:
    int helper(int n, int k) {
        if (k <= 1 || n == 1) {
            return k;
        }
        
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += helper(n-1, k-i);    
        }
        return ans;
    }
    
    int countVowelStrings(int n) {
        return helper(n, 5);
    }
};