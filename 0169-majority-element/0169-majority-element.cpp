class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int element=nums[0];
       int count=1;
       for(int i=1;i<nums.size();i++){
        if(element==nums[i]){
            count++;
        }else{
            if (count==0){
                element=nums[i];
                count=1;
            }else{
                count--;
            }
        }
       } 
       return element;
    }
};