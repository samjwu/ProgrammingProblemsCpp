class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        int ans = 0;
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                if (i == 0 || j == 0) {
                    memo[i][j] = 0;
                } else if (nums1[i-1] == nums2[j-1]) {
                    memo[i][j] = memo[i-1][j-1] + 1;
                    ans = max(ans, memo[i][j]);
                }
            }
        }
        
        return ans;
    }
};