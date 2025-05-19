class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count_zero = 0;
        int product_without_zero = 1,zero_index;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count_zero++;
                zero_index=i;
            } else {
                product_without_zero *= nums[i];
            }
        }
        vector<int>result(nums.size(),0);
        if (count_zero == 0) {
            for(int i=0;i<nums.size();i++){
                result[i]=product_without_zero/nums[i];
            }
        }else if(count_zero==1){
             result[zero_index]=product_without_zero;
        }
        return result;
    }
};