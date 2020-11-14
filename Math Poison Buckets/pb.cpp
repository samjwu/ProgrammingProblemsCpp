class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (minutesToDie > minutesToTest) {
            return 0;
        }
        
        int numTests = minutesToTest / minutesToDie;
        int ans = ceil(log(buckets) / log(numTests + 1));
        return ans;
    }
};