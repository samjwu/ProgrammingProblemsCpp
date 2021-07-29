class Solution {
public:
    int binSearchLow(vector<int>& nums, int target, int l, int r) {
        int m;
        while (l < r) {
            m = l + (r-l) / 2;
            if (nums[m] == target) {
                if (m == 0 || nums[m-1] < target) {
                    return m;
                } else {
                    r = m;
                }
            } else if (nums[m] < target) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return -1;
    }
    
    int binSearchHigh(vector<int>& nums, int target, int l, int r) {
        int m;
        while (l < r) {
            m = l + (r-l) / 2;
            if (nums[m] == target) {
                if (m == nums.size()-1 || nums[m+1] > target) {
                    return m;
                } else {
                    l = m+1;
                }
            } else if (nums[m] < target) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = binSearchLow(nums, target, 0, nums.size());
        int r = binSearchHigh(nums, target, 0, nums.size());
        return {l, r};
    }
};