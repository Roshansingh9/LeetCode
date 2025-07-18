class Solution {
    public int missingNumber(int[] nums) {
       int n=nums.length;
       int actual_sum=0;
       for(int i=0;i<n;i++){
actual_sum+=nums[i];
       } 
      int sum=n*(n+1)/2;
       return sum-actual_sum;
    }
}