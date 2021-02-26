class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        bool hasProblem = false;
        int start;
        int end;
        
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                hasProblem = true;
            }
            if (hasProblem) {
                smallest = min(smallest, nums[i]);
            }
        }
        
        hasProblem = false;
        
        for (int i=nums.size()-2; i>=0; i--) {
            if (nums[i] > nums[i+1]) {
                hasProblem = true;
            }
            if (hasProblem) {
                largest = max(largest, nums[i]);
            }
        }
        
        for (start=0; start<nums.size(); start++) {
            if (smallest < nums[start]) {
                break;
            }
        }
        
        for (end=nums.size()-1; end>=0; end--) {
            if (largest > nums[end]) {
                break;
            }
        }
        
        if (end - start < 0) {
            return 0;
        }
        
        return end - start + 1;
    }
};