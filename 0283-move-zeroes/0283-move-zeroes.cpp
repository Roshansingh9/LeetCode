class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>dummy(n);
        for(int i=0;i<n;i++){
            dummy[i]=nums[i];
        }
        int j=0;
        for(int i=0;i<n;i++){
           if(dummy[i]!=0){
            nums[j++]=dummy[i];
           }
        }
        for(int i=j;i<n;i++){
            nums[i]=0;
        }
        
    }
};