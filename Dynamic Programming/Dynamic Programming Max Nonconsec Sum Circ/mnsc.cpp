class Solution {
public:
    int rob_helper(vector<int>& nums) {
        if (nums.size() == 0) {
           return 0;
        }
        
        int memo1 = 0;
        int memo2 = nums[0];
        int temp;
        
        for (int i=1; i<nums.size(); i++) {
            temp = memo2;
            memo2 = max(nums[i] + memo1, memo2);
            memo1 = temp;
        }
        
        return memo2;
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+1, nums.end());
        
        return max(rob_helper(nums1), rob_helper(nums2));
    }
};