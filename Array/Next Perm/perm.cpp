class Solution {
public:
    void swap(vector<int>& nums, int pos1, int pos2) {
        int tmp = nums[pos2];
        
        nums[pos2] = nums[pos1];
        nums[pos1] = tmp;
    }
    
    void reverse(vector<int>& nums, int start) {
        int end = nums.size() - 1;
        
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int smaller = nums.size() - 2;
        
        while (smaller >= 0 && nums[smaller] >= nums[smaller+1]) {
            smaller--;
        }
        
        if (smaller >= 0) {
            int bigger = nums.size() - 1;
            while (bigger >= 0 && nums[smaller] >= nums[bigger]) {
                bigger--;
            }
            swap(nums, smaller, bigger);
        }
        
        reverse(nums, smaller + 1);
    }
};