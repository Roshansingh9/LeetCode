class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int zero=0,non_zero=0;
       int n=nums.size();
       for(non_zero;non_zero<n;non_zero++){
         if(nums[non_zero]!=0){
            swap(nums[zero],nums[non_zero]);
            zero++;
         }
         
       } 
    }
};