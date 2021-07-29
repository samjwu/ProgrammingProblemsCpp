class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        bool up;
        int i = 0;
        
        while (i < nums.size()-1) {
            if (nums[i] < nums[i+1]) {
                ans++;
                up = true;
            } else if (nums[i] > nums[i+1]) {
                ans++;
                up = false;
            } else {
                i++;
                continue;
            }

            while (i<nums.size()-1 && up && nums[i] <= nums[i+1]) {
                i++;
            }
            
            while (i<nums.size()-1 && !up && nums[i] >= nums[i+1]) {
                i++;
            }
        }
        
        return ans;
    }
};