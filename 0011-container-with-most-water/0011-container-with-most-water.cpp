class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int area = INT_MIN, side;
        while (start < end) {
            side = min(height[start],height[end]);
            area = max(area, side * (end-start));
            if (height[start]  < height[end ]) {
                start++;
            } else {
                end--;
            }
        }
        return area;
    }
};