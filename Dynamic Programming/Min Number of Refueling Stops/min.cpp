class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> memo(n+1);
        memo[0] = startFuel;
        
        for (int i=0; i<n; i++) {
            for (int j=i; j>=0; j--) {
                if (memo[j] >= stations[i][0]) {
                    memo[j+1] = max(memo[j+1], memo[j] + (long) stations[i][1]);
                }
            }
        }
        
        for (int i=0; i<=n; i++) {
            if (memo[i] >= target) {
                return i;
            }
        }
        
        return -1;
    }
};