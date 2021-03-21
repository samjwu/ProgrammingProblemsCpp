class Solution {
public:
    bool isPowerOf2(int N) {
        while (N % 2 == 0) {
            N /= 2;
        }
        
        return N == 1;
    }
    
    void swap(string& s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    
    bool permute(string s, int idx) {
        if (s.length() == idx) {
            if (s[0] == '0') {
                return false;
            }
            return isPowerOf2(stoi(s));
        }
        
        for (int i=idx; i<s.length(); i++) {
            swap(s, idx, i);
            if (permute(s, idx+1) == true) {
                return true;
            }
            swap(s, idx, i);
        }
        
        return false;
    }
    
    bool reorderedPowerOf2(int N) {
        string s = to_string(N);
        return permute(s, 0);
    }
};