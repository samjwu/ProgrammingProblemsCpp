class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        
        int start = nums.size();
        int end = 0;
        
        for (int i=0; i<nums.size(); i++) {
            if (copy[i] != nums[i]) {
                start = min(start, i);
                end = max(end, i);
            }
        }
        
        if (end - start >= 0) {
            return end - start + 1;
        }
        
        return 0;
    }
};