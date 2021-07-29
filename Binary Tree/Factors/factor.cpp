class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int prime = pow(10, 9) + 7;
        int n = arr.size();
        map<int, int> idx;
        
        sort(arr.begin(), arr.end());
        
        vector<long> memo(n, 1);
        
        for (int i=0; i<n; i++) {
            idx[arr[i]] = i;
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int r = arr[i] / arr[j];
                    if (idx.find(r) != idx.end()) {
                        memo[i] = (memo[i] + (memo[j] * memo[idx[r]])) % prime;
                    }
                }
            }
        }
        
        long ans = 0;
        for (long subans: memo) {
            ans += subans;
        }
        
        return (int) (ans % prime);
    }
};