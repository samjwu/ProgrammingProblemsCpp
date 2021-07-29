class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLeft(n), minRight(n);
        
        int currMax = nums[0];
        for (int i=0; i<n; i++) {
            currMax = max(currMax, nums[i]);
            maxLeft[i] = currMax;
        }
        
        int currMin = nums[n-1];
        for (int i=n-1; i>=0; i--) {
            currMin = min(currMin, nums[i]);
            minRight[i] = currMin;
        }
        
        for (int i=1; i<n; i++) {
            if (maxLeft[i-1] <= minRight[i]) {
                return i;
            }
        }

        return 1;
    }
};