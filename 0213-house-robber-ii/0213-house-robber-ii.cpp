class Solution {
    private:
    int solution(vector<int>& nums){
      int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

      
        int prev2=nums[0],prev1=max(nums[0],nums[1]);
       

        for(int i = 2; i < n; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
      vector<int> first;
      vector<int> last;
      
      int n=nums.size();
      
      if(n==1) return nums[0];
      for(int i=0;i<n;i++){
        if(i!=n-1) first.push_back(nums[i]);
        if(i!=0) last.push_back(nums[i]);
      }
      return max(solution(first),solution(last));  
    }
};