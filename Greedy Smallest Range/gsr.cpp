class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());

        int right = A[A.size() - 1] - K;
        int left = A[0] + K;
        int ans = right - left + 2 * K;
        
        for (int i = 0; i < A.size() - 1; i++) {
            int maxElem = max(A[i] + K, right);
            int minElem = min(left, A[i + 1] - K);
            ans = min(ans, maxElem - minElem);
        }
        
        return ans;
    }
};