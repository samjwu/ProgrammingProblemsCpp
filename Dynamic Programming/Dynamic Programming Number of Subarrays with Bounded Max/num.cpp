class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int n = nums.size();
        vector<int> memo(n);
        int prev = -1; // idx of last num greater than right
        
        for (int i=0; i<n; i++) {
            if (nums[i] < left && i > 0) {
                memo[i] = memo[i-1];
            }
            
            if (nums[i] > right) {
                memo[i] = 0;
                prev = i;
            }
            
            if (nums[i] >= left && nums[i] <= right) {
                memo[i] = i - prev;
            }
            
            ans += memo[i];
        }
        
        return ans;
    }
};