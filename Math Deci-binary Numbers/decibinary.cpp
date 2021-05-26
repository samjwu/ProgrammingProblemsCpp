class Solution {
public:
    int minPartitions(string n) {
        int highDigit = 0;
        
        for (char c: n) {
            highDigit = max(highDigit, (c-'0') % 10);
        }
        
        return highDigit;
    }
};