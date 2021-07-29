class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        string ans = dominoes;
        vector<int> dists(n, 0);
        int lDist = -1, rDist = -1;
        
        for (int i=0; i<n; i++) {
            if (dominoes[i] == 'R') {
                rDist = 0;
            } else if (dominoes[i] == 'L') {
                rDist = -1;
            } else if (rDist != -1) {
                rDist++;
                dists[i] = rDist;
                ans[i] = 'R';
            }
        }
        
        for (int i=n-1; i>=0; i--) {
            if (dominoes[i] == 'L') {
                lDist = 0;
            } else if (dominoes[i] == 'R') {
                lDist = -1;
            } else if (lDist != -1) {
                lDist++; 
                
                if (lDist < dists[i] || ans[i] == '.') {
                    ans[i] = 'L';
                } else if (lDist == dists[i]) {
                    ans[i] = '.';
                }
            }
        }
        
        return ans;
    }
};