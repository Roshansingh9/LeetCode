class Solution {
    private:
    int solution(vector<int>& nums,int index,vector<int>& dp){
      if(index>=nums.size()) return 0;
      if(dp[index]!=-1) return dp[index];
      int taken=solution(nums,index+2,dp)+nums[index];
      int not_taken=solution(nums,index+1,dp);
      return dp[index]=max(taken,not_taken);
    }
public:
    int rob(vector<int>& nums) {
      vector<int> first;
      vector<int> last;
      
      int n=nums.size();
      vector<int> dp1(n+1,-1);
      vector<int> dp2(n+1,-1);
      if(n==1) return nums[0];
      for(int i=0;i<n;i++){
        if(i!=n-1) first.push_back(nums[i]);
        if(i!=0) last.push_back(nums[i]);
      }
      return max(solution(first,0,dp1),solution(last,0,dp2));  
    }
};