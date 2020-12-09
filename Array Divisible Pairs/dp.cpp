class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        vector<int> remainders(60, 0);
        
        for (int song : time) {
            remainders[song % 60]++;
        }
        
        for (int i = 0; i <= 30; i++) {
            if (i == 0 || i == 30) {
                ans += remainders[i] * (remainders[i] - 1) / 2;
            } else {
                ans += remainders[i] * remainders[60 - i];
            }
        }
        
        return ans;
    }
};