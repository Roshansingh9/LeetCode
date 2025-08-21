class Solution {
public:
    void sortColors(vector<int>& nums) {
      int ones=0,zeros=0,twos=0;
      for(int i=0;i<nums.size();i++){
        if(nums[i]==0)zeros++;
        if(nums[i]==1)ones++;
        if(nums[i]==2)twos++;
      } 
      int i=0 ;
      for(i;i<zeros;i++){
        nums[i]=0;
      }
      for(i;i<zeros+ones;i++){
        nums[i]=1;
      }
      for(i;i<nums.size();i++){
        nums[i]=2;
      }
    }
};