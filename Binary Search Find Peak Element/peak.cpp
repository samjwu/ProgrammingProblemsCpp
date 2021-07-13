class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        
        int l = 0;
        int r = nums.size()-1;
        int m;
        
        if (nums[0] > nums[1]) {
            return 0;
        }
        
        if (nums[r] > nums[r-1]) {
            return r;
        }
        
        while (l < r) {
            m = l + (r - l)/2;
            
            if (nums[m] > nums[m+1]) { 
                r = m;
            } else { 
                l = m + 1;
            }
        }
        
        return l;
    }
};