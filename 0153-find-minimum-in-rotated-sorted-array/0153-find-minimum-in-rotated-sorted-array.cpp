class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            if(nums[left]<=nums[right]) return nums[left];
            else if(nums[left]>nums[right]){
                left++;
            }
        }
        return -1;
    }
};