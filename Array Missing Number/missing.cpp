class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int fullSum = 0;
        
        for (int i=0; i<=nums.size(); i++) {
            fullSum += i;
        }
        
        for (int n: nums) {
            fullSum -= n;
        }
        
        return fullSum;
    }
};