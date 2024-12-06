#include <vector>
#include <cmath>
#include <cstdlib>  // for rand() and RAND_MAX

class Solution {
private:
    double radius;   // radius of the circle
    double x_center; // x-coordinate of the circle's center
    double y_center; // y-coordinate of the circle's center

public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double angle;    // angle in radians
        double length;   // distance from the center to the random point

        double random = (double)rand() / RAND_MAX;  // random number between 0 and 1
        angle = random * 2 * M_PI;  // convert the random number to an angle in the range [0, 2π)

        double random2 = (double)rand() / RAND_MAX;
        length = sqrt(random2) * radius;  // randomly scaled length within the circle's radius

        // Calculate the coordinates of the random point using polar coordinates
        double x_random = x_center + length * cos(angle);
        double y_random = y_center + length * sin(angle);
        
        return vector<double>{x_random, y_random};  // return the random point as a vector
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */