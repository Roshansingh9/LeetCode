class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int candi=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==candi){
                count++;
            }else if(count==0){
                candi=nums[i];
                count=1;
            }else{
                count--;
            }
        }
        return candi;
    }
};