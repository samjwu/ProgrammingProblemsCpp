class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int decr = 0;
        int n = nums.size();
        
        for (int i=0; i<n-1; i++) {
            if (nums[i] > nums[i+1]) {
                decr++;
                
                if (decr > 1) {
                    break;
                }
                
                if (i == 0 || nums[i+1] >= nums[i-1]) {
                    nums[i] = nums[i+1];
                } else {
                    nums[i+1] = nums[i];
                }
            }
        }
        
        return decr <= 1;
    }
};