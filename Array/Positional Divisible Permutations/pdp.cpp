class Solution {
public:
    int permutations(int n, int pos, vector<bool>& used) {
        if (pos > n) {
            return 1;
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                continue;
            }
            
            if (i%pos != 0 && pos%i != 0) {
                continue;
            }
            
            used[i] = true;
            ans += permutations(n, pos+1, used);
            used[i] = false;
        }
        return ans;
    }
    
    int countArrangement(int n) {
        vector<bool> used(n+1, false);
        return permutations(n, 1, used);
    }
};