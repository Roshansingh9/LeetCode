class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int start=i+1,end=n-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(abs(target-sum)<abs(target-closest_sum)){
                    closest_sum=sum;
                }else if (sum<target){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return closest_sum;
    }
};