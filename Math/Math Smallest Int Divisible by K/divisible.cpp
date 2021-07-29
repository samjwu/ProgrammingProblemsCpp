class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) {
            return -1;
        }
        
        int ans = 1;
        int mod = ans % K;
        while (mod != 0) {
            mod = (mod * 10 + 1) % K;
            ans++;
        }
        
        return ans;
    }
};