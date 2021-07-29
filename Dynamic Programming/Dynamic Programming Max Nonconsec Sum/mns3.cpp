class Solution {
public:
    int rob(vector<int>& nums) {
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
};