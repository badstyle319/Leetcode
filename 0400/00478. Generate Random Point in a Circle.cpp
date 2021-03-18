class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double theta = 2 * M_PI * getRand();
        double len = r * sqrt(getRand());
        return {x + len * cos(theta), y + len * sin(theta)};
    }
private:
    double r, x, y;
    double getRand()
    {
        return (double) rand() / RAND_MAX;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */