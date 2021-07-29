class Solution {
public:
    double r, x, y;
    default_random_engine generator;
    uniform_real_distribution<double> distribution;
    
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
        distribution = uniform_real_distribution<double>(-r, r);
    }
    
    vector<double> randPoint() {
        
        double x_rand = distribution(generator) + x;
        double y_rand = distribution(generator) + y;
        
        while (pow(x_rand - x, 2) + pow(y_rand - y, 2) > pow(r, 2)) {
            x_rand = distribution(generator) + x;
            y_rand = distribution(generator) + y;
        }
        
        vector<double> ans = {x_rand, y_rand};
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */