class Solution {
public:
    int divResult(vector<int>& nums, double div) {
        int res = 0;
        for (int num:nums) {
            if (num > div) {
                res += ceil(num/div);
            } else {
                res += 1;
            }
        }
        return res;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            double div = l + (r-l)/2;
            int res = divResult(nums, div);
            if (res > threshold) {
                l = div + 1;    
            } else {
                r = div - 1;    
            }
        }
        return l;
    }
};