class Solution {
public:
    int rob_helper(vector<int> nums, int begin, int end) {
        int memo1 = 0;
        int memo2 = 0;
        int temp;
        
        for (int i=begin; i<end; i++) {
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
        
        return max(rob_helper(nums, 0, nums.size()-1), rob_helper(nums, 1, nums.size()));
    }
};