class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string sub;
        string final;
        
        for (char c : S) {
            if (isdigit(c)) {
                for (int i = 0; i < c - '0'; i++) {
                    sub += final;
                }
                final = sub;
                sub.clear();
            } else {
                final.push_back(c);
            }
        }
        
        string ans(1, final[K - 1]);
        return ans;
    }
};