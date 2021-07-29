class Solution {
public:
    static bool compEnv(vector<int>& e1, vector<int>& e2) {
        if (e1[0] == e2[0]) {
            return e1[1] > e2[1];
        }
        
        return e1[0] < e2[0];
    }
    
    bool smaller(vector<int>& e1, vector<int>& e2) {
        return e1[0] < e2[0] && e1[1] < e2[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        
        sort(envelopes.begin(), envelopes.end(), compEnv);
        
        vector<int> memo(n, 1);
        
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (smaller(envelopes[j], envelopes[i]) && memo[j]+1 > memo[i]) {
                    memo[i] = memo[j] + 1;
                }
            }
        }
        
        return *max_element(memo.begin(), memo.end());
    }
};