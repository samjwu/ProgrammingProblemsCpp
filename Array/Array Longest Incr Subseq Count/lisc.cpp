class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return len;
        }
        
        vector<int> lengths(len, 1);
        vector<int> count(len, 1);
        
        for (int i=0; i<len; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    if (lengths[j] >= lengths[i]) {
                        lengths[i] = lengths[j] + 1;
                        count[i] = count[j];
                    } else if (lengths[j] + 1 == lengths[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }
        
        int maxlength = *max_element(lengths.begin(), lengths.end());
        int ans = 0;
        for (int i=0; i<len; i++) {
            if (lengths[i] == maxlength) {
                ans += count[i];
            }
        }
        return ans;
    }
};