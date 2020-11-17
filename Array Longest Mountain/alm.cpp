class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans = 0;
        int idx = 0;
        
        while (idx < A.size()) {
            int base = idx;
            
            while (idx < A.size()-1 && A[idx] < A[idx+1]) {
                idx++;
            }
            
            if (idx == base) {
                idx++;
                continue;
            }
            
            int peak = idx;
            
            while (idx < A.size()-1 && A[idx] > A[idx+1]) {
                idx++;
            }
            
            if (idx == peak) {
                continue;
            }
            
            ans = max(ans, idx - base + 1);
        }
        
        return ans;
    }
};