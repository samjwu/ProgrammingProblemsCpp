class Solution {
public:
    void swap(string& s, int pos1, int pos2) {
        char tmp = s[pos1];
        s[pos1] = s[pos2];
        s[pos2] = tmp;
    }
    
    void reverse(string& s, int start, int end) {
        while (start < end) {
            swap(s, start, end);
            start++;
            end--;
        }
    }
    
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        
        int small = -1;
        for (int i = digits.length() - 1; i >= 1; i--) {
            if (digits[i-1] < digits[i]) {
                small = i - 1;
                break;
            }
        }
        
        if (small == -1) {
            return -1;
        }
        
        int large;
        for (int i = digits.length() - 1; i >= 0; i--) {
            if (digits[i] > digits[small]) {
                large = i;
                break;
            }
        }
        
        swap(digits, small, large);
        reverse(digits, small + 1, digits.length() - 1);
        
        long ans = stol(digits);
        
        if (ans > INT_MAX || ans <= n) {
            return -1;
        }
        return (int) ans;
    }
};