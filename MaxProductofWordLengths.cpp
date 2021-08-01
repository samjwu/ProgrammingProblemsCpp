class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> letterBitMaps(n);
        int ans = 0;
        
        for (int i=0; i<n; i++) {
            for (char c: words[i]) {
                letterBitMaps[i] |= 1 << (c-'a');
            }
        }
        
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                if ((letterBitMaps[i] & letterBitMaps[j]) == 0) {
                    ans = max(ans, (int) words[i].length() * (int) words[j].length());
                }
            }
        }
        
        return ans;
    }
};