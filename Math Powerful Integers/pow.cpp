class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ans;
        
        if (x == 1 && y == 1) {
            if (bound >= 2) {
                return {2};
            } else {
                return {};
            }
        }
        
        if (x == 1 || y == 1) {
            int hi = max(x, y);
            for (int i=0; pow(hi, i) + 1 <= bound; i++) {
                ans.insert(pow(hi, i) + 1);
            }
            
            return vector<int>(ans.begin(), ans.end());
        }
        
        for (int i=0; pow(x, i) <= bound; i++) {
            for (int j=0; pow(y, j) <= bound; j++) {
                int z = pow(x, i) + pow(y, j);
                if (z <= bound) {
                    ans.insert(z);
                }
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};