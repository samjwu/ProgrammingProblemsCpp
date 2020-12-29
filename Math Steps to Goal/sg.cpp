class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        
        int n = 0;
        while (target > 0) {
            n++;
            target -= n;
        }
        
        if (target%2 == 0) {
            return n;
        }
        return n + 1 + n%2;
    }
};