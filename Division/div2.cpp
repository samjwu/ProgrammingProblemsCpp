class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        
        if (dividend < 0) {
            sign *= -1;
        }
        if (divisor < 0) {
            sign *= -1;
        }
        
        long top = labs(dividend);
        long bot = labs(divisor);
        
        long ans = exp(log(top) - log(bot));
        
        if (ans > INT_MAX) {
            if (sign == -1) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }
        
        return sign * ans;
    }
};