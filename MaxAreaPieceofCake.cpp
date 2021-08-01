class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxHoriz = horizontalCuts[0], maxVert = verticalCuts[0];
        for (int i=0; i<horizontalCuts.size()-1; i++) {
            maxHoriz = max(maxHoriz, horizontalCuts[i+1] - horizontalCuts[i]);
        }
        for (int i=0; i<verticalCuts.size()-1; i++) {
            maxVert = max(maxVert, verticalCuts[i+1] - verticalCuts[i]);
        }
        
        int mod = pow(10, 9) + 7;
        return (long) maxHoriz * maxVert % mod;
    }
};