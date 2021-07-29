class Solution {
public:
    int ans = 0;
    
    int numSlices(vector<int>& A, int idx) {
        if (idx < 2) {
            return 0;
        }
        
        int sliceCount = 0;
        if (A[idx]-A[idx-1] == A[idx-1]-A[idx-2]) {
            sliceCount = numSlices(A, idx-1) + 1;
            ans += sliceCount;
        } else {
            numSlices(A, idx-1);
        }
        
        return sliceCount;
    }
    
    int numberOfArithmeticSlices(vector<int>& A) {
        numSlices(A, A.size()-1);
        return ans;
    }
};