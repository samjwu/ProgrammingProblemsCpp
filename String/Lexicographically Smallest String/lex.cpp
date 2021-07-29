class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        
        int zCount = (k-n) / 25;
        int remainder = (k-n) - (25*zCount);
        
        for (int i = 0; i < zCount; i++) {
            ans[n-1-i] = 'z';
        }
        
        if (remainder > 0) {
            ans[n-1-zCount] = 'a' + remainder;
        }
        
        return ans;
    }
};