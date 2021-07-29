class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        
        auto minMax = minmax_element(nums.begin(), nums.end());
        int minElem = *minMax.first;
        int maxElem = *minMax.second;
        
        // set gap to 1 at min to prevent division by 0
        int gap = max((maxElem - minElem) / (n-1), 1);
        int numBuckets = (maxElem - minElem) / gap + 1;
        
        vector<int> minBuckets(numBuckets, INT_MAX);
        vector<int> maxBuckets(numBuckets, INT_MIN);
        
        // determine bucket number of each number in nums
        for (int num: nums) {
            int k = (num - minElem) / gap; // kth bucket number
            
            if (num < minBuckets[k]) {
                minBuckets[k] = num;
            }
            if (num > maxBuckets[k]) {
                maxBuckets[k] = num;
            }
        }
        
        int i = 0, j; 
        int maxGap = maxBuckets[0] - minBuckets[0];
        
        while (i < numBuckets) {
            j = i + 1;
            
            while (j < numBuckets && minBuckets[j] == INT_MAX && maxBuckets[j] == INT_MIN) {
                j++;
            }
            if (j == numBuckets) {
                break;
            }
            
            maxGap = max(maxGap, minBuckets[j] - maxBuckets[i]);
            i = j;
        }
        
        return maxGap;
    }
};