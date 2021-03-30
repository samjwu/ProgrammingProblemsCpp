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
    
    int binarySearch(int l, int r, int val, vector<int>& memo) {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            
            if (memo[m] >= val) {
                r = m;
            } else {
                l = m;
            }
        }
        
        return r;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        
        sort(envelopes.begin(), envelopes.end(), compEnv);
        
        vector<int> memo(n, 0);
        int length = 1;
        
        memo[0] = envelopes[0][1];
        for (int i=1; i<n; i++) {
            int height = envelopes[i][1];
            
            if (height < memo[0]) {
                memo[0] = height;
            } else if (height > memo[length-1]) {
                memo[length] = height;
                length++;
            } else {
                int replace = binarySearch(-1, length-1, height, memo);
                memo[replace] = height;
            }
        }
        
        return length;
    }
};