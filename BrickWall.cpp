class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int m = wall.size();
        
        int n = 0;
        for (int brick: wall[0]) {
            n += brick;
        }
        
        unordered_map<int, int> edges;
        
        for (int i=0; i<m; i++) {
            int pos = 0;
            for (int brick: wall[i]) {
                pos += brick;
                if (pos > 0 && pos < n) {
                    edges[pos]++;
                }
            }
        }
        
        int ans = m;
        for (auto pair: edges) {
            ans = min(ans, m - pair.second);
        }
        
        return ans;
    }
};