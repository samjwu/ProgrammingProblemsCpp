class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        
        int num_diff = 0;
        map<int, int> freqA;
        map<int, int> freqB;
        for (int i=0; i<26; i++) {
            freqA[i] = 0;
            freqB[i] = 0;
        }
        for (int i=0; i<A.length(); i++) {
            freqA[A[i] - 'a'] += 1;
            freqB[B[i] - 'a'] += 1;
            if (A[i] != B[i]) {
                num_diff += 1;
            }
        }
        
        bool ans = false;
        if (num_diff == 0) {
            for (int i=0; i<freqA.size(); i++) {
                if (freqA[i] > 1) {
                    ans = true;
                }
            }
        } else if (num_diff == 2) {
             for (int i=0; i<freqA.size(); i++) {
                 if (freqA[i] != freqB[i]) {
                     ans = false;
                     break;
                 } else {
                     ans = true;
                 }
             }
        } else {
            ans = false;
        }
        
        return ans;
    }
};