class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int memo = 0;
        int prev = -1; // idx of last num greater than right
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < left) {
                ans += memo;
            }
            
            if (nums[i] > right) {
                memo = 0;
                prev = i;
            }
            
            if (nums[i] >= left && nums[i] <= right) {
                memo = i - prev;
                ans += memo;
            }
        }
        
        return ans;
    }
};