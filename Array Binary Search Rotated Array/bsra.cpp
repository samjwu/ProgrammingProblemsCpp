class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int m;
        bool targetfirsthalf, midfirsthalf;
        while (l <= r) {
            m = l + (r-l)/2;
            if (nums[m] == target) {
                return true;
            }
            
            if (nums[l] == nums[m]) {
                l++;
                continue;
            }
            
            if (nums[l] <= target) {
                targetfirsthalf = true;
            } else {
                targetfirsthalf = false;
            }
            if (nums[l] <= nums[m]) {
                midfirsthalf = true;
            } else {
                midfirsthalf = false;
            }
            
            if (targetfirsthalf && !midfirsthalf || !targetfirsthalf && midfirsthalf) {
                if (midfirsthalf) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            } else {
                if (nums[m] < target) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
        }
        
        return false;
    }
};