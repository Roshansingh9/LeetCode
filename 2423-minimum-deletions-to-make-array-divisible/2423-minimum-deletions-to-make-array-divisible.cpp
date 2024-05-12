class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        if(nums[0]==1)return 0;
        int g = 0;
        for(auto &i: numsDivide){
            g = __gcd(g,i);
        }
        if(g==1||g<nums[0]){
            return -1;
        }
        int i;
        for(i = 0;i<nums.size();i++){
            if(g%nums[i] == 0){
                return i;
            }
        }
        return -1;

    }
};