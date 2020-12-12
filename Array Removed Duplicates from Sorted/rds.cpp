class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        
        int count = 0;
        int prev = nums[size - 1];
        int curr;
        
        for (int i = size - 2; i >= 0; i--) {
            curr = nums[i];
            
            if (prev == curr && count == 0) {
                count = 2;
            } else if (prev == curr && count > 0) {
                count++;
            } else {
                count = 0;
            }
            
            if (prev == curr && count > 2) {
                nums.erase(nums.begin() + i);
            }
            
            prev = nums[i];
        }
        
        return nums.size();
    }
};