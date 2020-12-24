class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        
        next_permutation(digits.begin(), digits.end());
        
        long ans = stol(digits);
        
        if (ans > INT_MAX || ans <= n) {
            return -1;
        }
        return (int) ans;
    }
};