class Solution {
public:
    int minOperations(int n) {
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += (2 * i) + 1;
        }
        
        int target = sum / n;
        
        int ops = 0;
        for (int i=0; i<n/2; i++) {
            ops += target - ((2 * i) + 1);
        }
        
        return ops;
    }
};