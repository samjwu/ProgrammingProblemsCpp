class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long length = 0;
        long idx;
        
        for (idx = 0; length < K; idx++) {
            if (isdigit(S[idx])) {
                length *= S[idx] - '0';
            } else {
                length++;
            }
        }
        
        while (idx--) {
            if (isdigit(S[idx])) {
                length /= S[idx] - '0';
                K %= length;
            } else if (K % length-- == 0) {
                return string(1, S[idx]);
            }
        }
        
        return "";
    }
};