class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        
        int ans = 0;
        vector<int> maxLeft(n), maxRight(n);
        maxLeft[0] = height[0];
        maxRight[n-1] = height[n-1];
        
        for (int i=1; i<n; i++) {
            maxLeft[i] = max(height[i], maxLeft[i-1]);
        }
        
        for (int i=n-2; i>=0; i--) {
            maxRight[i] = max(height[i], maxRight[i+1]);
        }
        
        for (int i=1; i<n-1; i++) {
            ans += min(maxLeft[i], maxRight[i]) - height[i];
        }
        
        return ans;
    }
};