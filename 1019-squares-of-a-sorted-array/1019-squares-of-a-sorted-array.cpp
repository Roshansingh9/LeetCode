class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int n=nums.size();
       int start=0,end=n-1,i=n-1;
       vector<int>result(n); 
       while(start<=end){
        if (abs(nums[start])<=abs(nums[end])){
            result[i--]=nums[end]*nums[end];
            end--;
        }else {
            result[i--]=nums[start]*nums[start];
            start++; 
        }
       }
       return result;
    }
};