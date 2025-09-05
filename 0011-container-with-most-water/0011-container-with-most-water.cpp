class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int start=0;
        int end=n-1;
        int max_water=INT_MIN;
        while(start<=end){
           int area=min(height[start],height[end])*(end-start);
           max_water=max(max_water,area);
           if(height[start]<=height[end]){
            start++;
           }else{
            end--;
           }
        }
        return max_water;
    }
};