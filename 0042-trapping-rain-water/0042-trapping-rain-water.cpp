class Solution {
    private:
    vector<int>prefixsum(vector<int>& heights){
        int n=heights.size();
        vector<int>result(n);
        result[0]=heights[0];
        for(int i=1;i<n;i++){
            result[i]=max(heights[i],result[i-1]);
        }
        return result;
    }
    vector<int>suffixsum(vector<int>& heights){
        int n=heights.size();
        vector<int>result(n);
        result[n-1]=heights[n-1];
        for(int i=n-2;i>0;i--){
            result[i]=max(heights[i],result[i+1]);
        }
        return result;
    }
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>presum=prefixsum(height);
        vector<int>sufsum=suffixsum(height);
        int total=0;
        for(int i=0;i<n;i++){
            int maxleft=presum[i],maxright=sufsum[i];
            if(maxleft>height[i] && maxright>height[i])
            total+=(min(maxleft,maxright)-height[i]);
        }
        return total;
    }
};