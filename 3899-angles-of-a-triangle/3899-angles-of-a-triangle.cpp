class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        vector<double> result(3);
        if (sides[0] + sides[1] <= sides[2]) {
            return {};
        }
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];
        result[0] = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / M_PI;
        result[1] = acos((a * a + c * c - b * b) / (2 * a * c)) * 180.0 / M_PI;
        result[2] = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / M_PI;
         sort(result.begin(),result.end());
         return result;
    }
};