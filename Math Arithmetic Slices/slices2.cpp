class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int count = 0;
        int ans = 0;
        
        int idx = 2;
        while (idx < A.size()) {
            if (A[idx]-A[idx-1] == A[idx-1]-A[idx-2]) {
                count++;
                ans += count;
            } else {
                count = 0;
            }
            idx++;
        }
        
        return ans;
    }
};