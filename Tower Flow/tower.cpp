class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double glasses[101][101] = {0.0};
        
        glasses[0][0] = (double) poured;
        
        for (int row = 0; row <= query_row; row++) {
            for (int col = 0; col <= row; col++) {
                double flow = glasses[row][col];
                double single_flow = (flow - 1) / 2;
                if (flow >= 1) {
                    glasses[row+1][col] += single_flow;
                    glasses[row+1][col+1] += single_flow;
                    glasses[row][col] = 1;
                }
            }
        }

        return glasses[query_row][query_glass];
    }
};