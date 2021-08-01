class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        
        while (X < Y) {
            if (Y%2 == 1) {
                Y++;
            } else {
                Y /= 2;
            }
            
            ans++;
        }
        
        return ans + X - Y;
    }
};