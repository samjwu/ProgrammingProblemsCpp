class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            } else if (divisor == 1) {
                return INT_MIN;
            } else {
                dividend += abs(divisor);
                ans++;
            }
        }
        
        if (divisor == INT_MIN) {
            return dividend == divisor;
        }

        int sign = 1;
        
        if (dividend < 0) {
            sign *= -1;
        }
        if (divisor < 0) {
            sign *= -1;
        }
        
        if (dividend == divisor) {
            return sign;
        }
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        for (int i=0; dividend>=divisor; i=0) {
            while (dividend >> i >= divisor) {
                i++;
            }
            
            dividend -= divisor << i-1;
            ans += 1 << i-1;
        }
        
        return sign * ans;
    }
};