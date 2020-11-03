class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        
        if (A.compare(B) == 0) {
            int freq[26] = {};
            for (int i=0; i<A.length(); i++) {
                freq[A[i] - 'a'] += 1;
            }
            
            for (int i=0; i<(sizeof(freq)/sizeof(freq[0])); i++) {
                if (freq[i] > 1) {
                    return true;
                }
            }
            
            return false;
        } else {
            int idx1 = -1;
            int idx2 = -1;
            for (int i=0; i<A.length(); i++) {
                if (A[i] != B[i]) {
                    if (idx1 == -1) {
                        idx1 = i;
                    } else if (idx2 == -1) {
                        idx2 = i;
                    } else {
                        return false;
                    }
                }
            }
            
            return (idx2 != -1 && A[idx1] == B[idx2] && B[idx1] == A[idx2]);
        }
    }
};