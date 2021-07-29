class Solution {
public:
    static bool compareRanges(vector<int>& point1, vector<int>& point2) {
        return (point1[1] < point2[1]);
    }
    
    int findMinPoints(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        } else if (points.size() == 1) {
            return 1;
        }
        
        sort(points.begin(), points.end(), compareRanges);
        int sum = 1;
        int xend = points[0][1];
        
        for (int i=1; i<points.size(); i++) {
            if (points[i][0] <= xend) {
                continue;
            }
            xend = points[i][1];
            sum++;
        }
        return sum;
    }
};