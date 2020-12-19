class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        
        for (int i = 0; i < nums.size() - 2; i++) {
            
            for (int j = i + 1; j < nums.size() - 1; j++) {
                while (j < nums.size() - 1 && nums[j] <= nums[i]) {
                    j++;
                }
                
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[k] > nums[j] && nums[j] > nums[i]) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};