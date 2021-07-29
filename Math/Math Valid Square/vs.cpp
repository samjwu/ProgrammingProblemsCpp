class Solution {
public:
    double distance(vector<int>& p1, vector<int>& p2) {
        double x = pow(p2[0] - p1[0], 2);
        double y = pow(p2[1] - p1[1], 2);
        return sqrt(x + y);
    }
    
    bool isSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return distance(p1, p2) == distance(p2, p3) && distance(p2, p3) == distance(p3, p4) && 
            distance(p3, p4) == distance(p4, p1) && distance(p1, p3) == distance(p2, p4) &&
            distance(p1, p2) > 0;
    }
    
    void swapPoints(vector<vector<int>>& points, int a, int b) {
        vector<int> tmp = points[a];
        points[a] = points[b];
        points[b] = tmp;
    }
    
    bool pointPermutations(vector<vector<int>>& points, int iter) {
        if (iter == 4) {
            return isSquare(points[0], points[1], points[2], points[3]);
        } else {
            bool ans = false;
            for (int i=0; i<4; i++) {
                swapPoints(points, i, iter);
                ans = ans | pointPermutations(points, iter + 1);
                swapPoints(points, i, iter);
            }
            return ans;
        }
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        bool ans = pointPermutations(points, 0);
        return ans;
    }
};